#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#define asleep(n) Sleep(n)

int main () {
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);

	socket.bind ("tcp://*:5555");
	while (true) {
		zmq::message_t request;
		zmq::message_t reply (5);
		memcpy (reply.data (), "World", 5);

		socket.recv (&request);

		std::cout << "Received Hello" << std::endl; sleep(1);

		socket.send (reply);
	}
	return 0;
}
