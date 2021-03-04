#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main () {
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);

	socket.bind ("tcp://*:5555");
	while (true) {
		zmq::message_t request;
		zmq::message_t reply (5);

		socket.recv (&request);
		std::cout
 			<< "Received: "
			<< std::string(static_cast<char*>(request.data()), request.size())
			<< std::endl; sleep(1);

		memcpy(reply.data(), "World", 5);
		std::cout
			<< "Replying: "
			<< std::string(static_cast<char*>(reply.data()), reply.size())
			<< std::endl << std::endl;
		socket.send (reply);
	}
	return 0;
}
