#include<iostream>
#include"blocking_queue.h"
#include<boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class QueuePopWorker {
	BlockingQueue<int>& queue;
	std::vector<int> results;
	int delay;
public:
	QueuePopWorker(BlockingQueue<int>& queue, int delay): queue(queue), delay(delay) {}
	void start() {
		int result;
		while(queue.pop(result)) {
			boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
			results.push_back(result);
		}
		std::cerr<<"queue.empty() :"<<queue.empty() <<"=="<<true<<std::endl;
		std::cerr<<"queue.closed():"<<queue.closed()<<"=="<<true<<std::endl;
	}
};
class QueuePushWorker {
	BlockingQueue<int>& queue;
	std::vector<int> data;
	bool should_close;
	int delay;
public:
	QueuePushWorker(BlockingQueue<int>& queue, std::vector<int> data, bool should_close, int delay)
		: queue(queue), data(data), should_close(should_close), delay(delay) {}
	void start() {
		int result;
		for (auto value: data) {
			boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
			queue.push(value);
		}
		if (should_close) { queue.close(); }
	}
};

int main() {{
	BlockingQueue<int> queue(5);
	std::vector<int> data;
	for(int i=0; i<10; ++i) { data.push_back(i+1); }
	QueuePushWorker producer(queue, data, true, 0);
	QueuePopWorker consumer(queue, 1000);
	boost::thread consumer_thread(&QueuePopWorker::start, &consumer);
	boost::thread producer_thread(&QueuePushWorker::start, &producer);
	producer_thread.join();
	consumer_thread.join();
}{
	BlockingQueue<int> queue(5);
	std::vector<int> data;
	for(int i=0; i<10; ++i) { data.push_back(i+1); }
	QueuePushWorker producer(queue, data, true, 1000);
	QueuePopWorker consumer(queue, 0);
	boost::thread consumer_thread(&QueuePopWorker::start, &consumer);
	boost::thread producer_thread(&QueuePushWorker::start, &producer);
	producer_thread.join();
	consumer_thread.join();
}}
