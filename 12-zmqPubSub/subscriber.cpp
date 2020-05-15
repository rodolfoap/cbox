#include <zmq.hpp>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[]) {
	zmq::context_t context (1);
	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.connect("tcp://localhost:5556");

	const char *filter = (argc > 1)? argv [1]: "10001 ";
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen (filter));

	int update_nbr;
	long total_temp = 0;
	for (update_nbr = 0; update_nbr < 100; update_nbr++) {
		int zipcode, temperature, relhumidity;
		zmq::message_t update;
		std::istringstream iss(static_cast<char*>(update.data()));

		subscriber.recv(&update);

		iss >> zipcode >> temperature >> relhumidity ;
		total_temp += temperature;
		std::cout << "." << std::flush;
	}
	std::cout << "\nAverage temperature for zipcode '"<< filter
		  <<"' was "<<(int) (total_temp / update_nbr) <<"F"
		  << std::endl;
	return 0;
}
