#include <queue>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

// Based on https://gist.github.com/PolarNick239/f727c0cd923398dc397a05f515452123
template<typename Data> class BlockingQueue {

private:
	std::queue<Data>            queue;
	mutable boost::mutex        queue_mutex;
	bool                        is_closed = false;
	boost::condition_variable   pushed_or_closed_event;
	boost::condition_variable   pop_event;

public:
	const size_t                queue_limit;

	BlockingQueue(size_t size_limit=0): queue_limit(size_limit) {}

	void print_queue(std::queue<Data> q, char c, Data d) {
		std::cerr<<"Q("<<c<<d<<"): ";
		while (!q.empty()) { std::cerr<<q.front()<<" "; q.pop(); }
		std::cerr<<"["<<queue.size()<<"/"<<queue_limit<<"]"<<std::endl;
	}

	void push(const Data& data) {
		boost::mutex::scoped_lock lock(queue_mutex);
		if (queue_limit > 0) while (queue.size() >= queue_limit) pop_event.wait(lock);
		assert (!is_closed);
		queue.push(data);
		print_queue(queue, '+', data);
		lock.unlock();
		pushed_or_closed_event.notify_one();
	}

	// This checks if push() can be performed; instead of blocking, returns false.
	bool try_push(const Data& data) {
		boost::mutex::scoped_lock lock(queue_mutex);
		if (queue_limit > 0) if (queue.size() >= queue_limit) return false;
		assert (!is_closed);
		queue.push(data);
		print_queue(queue, '+', data);
		lock.unlock();
		pushed_or_closed_event.notify_one();
		return true;
	}

	void close() {
		boost::mutex::scoped_lock lock(queue_mutex);
		assert (!is_closed);
		is_closed = true;
		lock.unlock();
		pushed_or_closed_event.notify_all();
	}

	bool pop(Data &popped_value) {
		boost::mutex::scoped_lock lock(queue_mutex);
		while (queue.empty()) {
			if (is_closed) return false;
			pushed_or_closed_event.wait(lock);
		}
		popped_value = queue.front();
		queue.pop();
		print_queue(queue, '-', popped_value);
		pop_event.notify_one();
		return true;
	}

	// This checks if pop() can be performed; instead of blocking, returns false.
	bool try_pop(Data &popped_value) {
		boost::mutex::scoped_lock lock(queue_mutex);
		if (queue.empty()) return false;
		popped_value = queue.front();
		queue.pop();
		pop_event.notify_one();
		return true;
	}

	bool empty() const {
		boost::mutex::scoped_lock lock(queue_mutex);
		return queue.empty();
	}

	bool closed() const {
		boost::mutex::scoped_lock lock(queue_mutex);
		return is_closed;
	}

	size_t limit() const {
		return queue_limit;
	}

	size_t size() const {
		boost::mutex::scoped_lock lock(queue_mutex);
		return queue.size();
	}
};
