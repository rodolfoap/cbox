#include <zmq.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fmt/format.h>
#define randomf(n1, n2) (((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

class Server {
public:
	Server() {
		std::thread tsend=std::thread(&Server::fsend, this);
		std::thread tsink=std::thread(&Server::fsink, this);
                tsend.join();
                tsink.join();
	}
private:
	zmq::message_t getMessage(std::string s) {
		int length=s.length();
		zmq::message_t message(length);
		memcpy(message.data(), s.c_str(), length);
		return message;
	}
	std::string getString(zmq::message_t* m) {
		std::string r(static_cast<char*>(m->data()), (m->size()));
		return r;
	}
	void fsend(){
		zmq::context_t context(1);
		// The Ventilator
		zmq::socket_t sockSend(context, ZMQ_PUB);
		sockSend.bind("tcp://*:5557");
		log("Ventilator: tcp://*:5557");
		while(1){
			std::string pkt=fmt::format("SINK:{}", randomf(100, 200));
			sockSend.send(getMessage(pkt));
			// log("SENT: "<<pkt);
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
