#include <zmq.hpp>
#include <string>
#include <iostream>

int main () {
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REQ);

	std::cout << "Connecting to hello world server..." << std::endl;
	socket.connect ("tcp://localhost:5555");

	for (int count=0; count!=10; count++) {
		zmq::message_t request (5);
		zmq::message_t reply;
		memcpy (request.data (), "Hello", 5);

		std::cout << "Sending Hello #" << count << std::endl;
		socket.send (request);

		socket.recv (&reply);
		std::cout << "Received World #" << count << std::endl;
	}
	return 0;
}
