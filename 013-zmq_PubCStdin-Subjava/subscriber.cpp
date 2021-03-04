#include <zmq.hpp>
#include <iostream>
#include <sstream>

char none[0];
int main (int argc, char *argv[]) {
	zmq::context_t context (1);
	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.connect("tcp://localhost:5556");
	subscriber.setsockopt(ZMQ_SUBSCRIBE, none);

	for (int count=0; count<4; count++) {
		char json[255];
		zmq::message_t update;

		subscriber.recv(&update);
		std::istringstream iss(static_cast<char*>(update.data()));
		iss >> json;

		std::cerr << "SUB: Received message [" << count<< "]: "
			  << json << "\n" << std::endl;
	}
	return 0;
}
