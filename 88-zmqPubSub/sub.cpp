#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Client {
public:
	Client() {
		std::thread tsub=std::thread(&Client::fsub, this);
                tsub.join();
	}
private:
	void fsub(){
		zmq::context_t context(1);
		// The Subscriber
		zmq::socket_t sockRcpt(context, ZMQ_SUB);
		sockRcpt.setsockopt(ZMQ_SUBSCRIBE, "", 0);
		sockRcpt.connect("tcp://127.0.0.1:5557");
		log("Receiver: tcp://127.0.0.1:5557");
		while(1){
			zmq::message_t message;
			sockRcpt.recv(&message);
			std::string smessage=getString(&message);
			log("RECEIVED: "<<smessage);
		}
	}
};

int main(int argc, char *argv[]) {
	Client s;
	return 0;
}
