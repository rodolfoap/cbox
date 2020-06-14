#include <zmq.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fmt/format.h>
#include "json.hpp"
#include "functions.cpp"
#define randomf(n1, n2) (((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

class Client {
public:
	Client() {
		std::thread tsend=std::thread(&Client::fsend, this);
		std::thread trcpt=std::thread(&Client::frcpt, this);
                tsend.join();
                trcpt.join();
	}
private:
	void fsend(){
		zmq::context_t context(1);
		// The Sender
		zmq::socket_t sockSend(context, ZMQ_PUSH);
		sockSend.connect("tcp://127.0.0.1:5558");
		log("Sender: tcp://127.0.0.1:5558");
		while(1) {
			std::string pkt=fmt::format("WORKER:{}", randomf(200, 300));
			sockSend.send(getMessage(pkt));
			// log("SENT: "<<pkt);
			std::this_thread::sleep_for(std::chrono::milliseconds(555));
		}
	}
	void frcpt(){
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
	Client c;
	return 0;
}
