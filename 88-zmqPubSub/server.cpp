#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Server {
public:
	Server() {
		std::thread tpub=std::thread(&Server::fpub, this);
		std::thread tsub=std::thread(&Server::fsub, this);
                tpub.join();
                tsub.join();
	}
private:
	void fpub(){
		zmq::context_t context(1);
		// The Ventilator
		zmq::socket_t sockSend(context, ZMQ_PUB);
		sockSend.bind("tcp://*:5557");
		log("Ventilator: tcp://*:5557");
		while(1){
			Message m("raisealert");
			m.addOptns("requireack", "true");
			m.addParam("priority", "0");
			m.addParam("text", fmt::format("Collapsing probability is: {}", frandom(0, 1)));
			sockSend.send(getMessage(m.getJson()));
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
	void fsub(){
		zmq::context_t context(1);
		// The Receiver
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
	Server s;
	return 0;
}
