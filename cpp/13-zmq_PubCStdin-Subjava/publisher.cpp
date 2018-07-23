#include <iostream>
#include <zmq.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#if (defined (WIN32))
#include <zhelpers.hpp>
#endif
#define within(num) (int) ((float) num * random () / (RAND_MAX + 1.0))

int main (int argc, char *argv[]) {
	srandom ((unsigned) time (NULL));
	zmq::context_t context (1);
	zmq::socket_t publisher (context, ZMQ_PUB);
	publisher.bind("tcp://*:5556");

	for(int count=0; count<5; count++) {
		zmq::message_t json(20);
		strcpy((char *)json.data(), argv[1]);
		sleep(1);
		publisher.send(json);
		std::cerr << "PUB: Sent message [" << count << "]: "
			  << argv[1] << std::endl;
	}
	return 0;
}
