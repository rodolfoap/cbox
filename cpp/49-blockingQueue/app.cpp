#include<iostream>
#include"blocking_queue.h"
#include<boost/thread/thread.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class QueuePopWorker {
	BlockingQueue<int>& queue;
	int delay;
public:
	QueuePopWorker(BlockingQueue<int>& queue, int delay): queue(queue), delay(delay) {}
	void start() {
		int result;
		while(queue.pop(result)) {
			boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
		}
		std::cerr<<"queue.empty() :"<<queue.empty() <<"=="<<true<<std::endl;
		std::cerr<<"queue.closed():"<<queue.closed()<<"=="<<true<<std::endl;
	}
};
class QueuePushWorker {
	BlockingQueue<int>& queue;
	bool should_close;
	int delay;
public:
	QueuePushWorker(BlockingQueue<int>& queue, bool should_close, int delay)
		: queue(queue), should_close(should_close), delay(delay) {}

	void start() {
		int result;
		for(int i=0; i<10; ++i) {
			boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
			queue.push(i);
		}
		if (should_close) { queue.close(); }
	}
};

int main() {{
	// Fast producer, slow consumer
	BlockingQueue<int> queue(5);
	QueuePushWorker producer(queue, true, 0);
	QueuePopWorker  consumer(queue, 500);
	boost::thread consumer_thread(&QueuePopWorker ::start, &consumer);
	boost::thread producer_thread(&QueuePushWorker::start, &producer);
	producer_thread.join();
	consumer_thread.join();
}{
	// Slow producer, fast consumer
	BlockingQueue<int> queue(5);
	QueuePushWorker producer(queue, true, 500);
	QueuePopWorker  consumer(queue, 0);
	boost::thread producer_thread(&QueuePushWorker::start, &producer);
	boost::this_thread::sleep(boost::posix_time::milliseconds(3000));
	boost::thread consumer_thread(&QueuePopWorker ::start, &consumer);
	producer_thread.join();
	consumer_thread.join();
}}
