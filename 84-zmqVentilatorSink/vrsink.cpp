#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Server {
public:
	Server() {
		std::thread tsend=std::thread(&Server::fsend, this);
		std::thread tsink=std::thread(&Server::fsink, this);
                tsend.join();
                tsink.join();
	}
private:
	void fsend(){
		Message m("raisealert");
		m.addParam("text", "Hello, World");
		m.addParam("priority", "0");
		m.addOptns("requireack", "true");

		zmq::context_t context(1);
		// The Ventilator
		zmq::socket_t sockSend(context, ZMQ_PUB);
		sockSend.bind("tcp://*:5557");
		log("Ventilator: tcp://*:5557");
		while(1){
			m.setParam("text", fmt::format("Collapsing probability is: {}", frandom(0, 1)));
			sockSend.send(getMessage(m.getJson()));
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
	void fsink(){
		zmq::context_t context(1);
		// The Sink
		zmq::socket_t sockSink(context, ZMQ_PULL);

		sockSink.bind("tcp://*:5558");
		log("Sink: tcp://*:5558");
		while(1){
			zmq::message_t message;
			sockSink.recv(&message);
			std::string smessage=getString(&message);
			log("RECEIVED: "<<smessage);
		}
	}
};

int main(int argc, char *argv[]) {
	Server s;
	return 0;
}
