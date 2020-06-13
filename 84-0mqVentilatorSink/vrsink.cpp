#include <zmq.hpp>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#define within(num) (int)((float)num * random() / (RAND_MAX + 1.0))
#define log(text)(std::cerr<<text<<std::endl)

int main(int argc, char *argv[]) {
	zmq::context_t context(1);
	zmq::socket_t sender(context, ZMQ_PUSH);
	zmq::socket_t sink(context, ZMQ_PUSH);
	sender.bind("tcp://*:5557");
	log("Ventilator: tcp://127.0.0.1:5557");
	sink.connect("tcp://127.0.0.1:5558");
	log("Sink: tcp://127.0.0.1:5557");

	//  The first message is "0" and signals start of batch
	zmq::message_t message(2);
	memcpy(message.data(), "0", 1);
	sink.send(message);
	log("SENT: SOC [0]");

	//  Initialize random number generator
	srandom((unsigned)time(NULL));

	//  Send 100 tasks
	int task_nbr;
	int total_msec=0; //  Total expected cost in msecs
	for(task_nbr=0; task_nbr<100; task_nbr++) {
		int workload;
		//  Random workload from 1 to 100msecs
		workload=within(100) + 1;
		total_msec+=workload;

		message.rebuild(10);
		memset(message.data(), '\0', 10);
		sprintf((char *)message.data(), "%d", workload);
		sender.send(message);
	}
	std::cout<<"Total expected cost: "<<total_msec<<" msec"<<std::endl;
	sleep(1); //  Give 0MQ time to deliver

	return 0;
}
