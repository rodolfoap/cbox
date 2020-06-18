#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Client {
public:
        Client(char* url): url(url) {
                std::thread tsub=std::thread(&Client::fsub, this);
                tsub.join();
        }
private:
	char* url;
	void fsub() {
		zmq::context_t context(1);
		// The Subscriber
		zmq::socket_t sockRcpt(context, ZMQ_SUB);
		sockRcpt.setsockopt(ZMQ_SUBSCRIBE, "", 0);
		sockRcpt.connect(url);
		log("Subscriber: "<<url);
		while(1){
			zmq::message_t message;
			sockRcpt.recv(&message);
			std::string smessage=getString(&message);
			log("RECEIVED: "<<smessage);
		}
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Client s(argv[1]);
	return 0;
}
