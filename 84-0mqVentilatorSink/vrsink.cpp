#include <zmq.hpp>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <fmt/format.h>
#define randint(n1, n2) (int)(((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

class Server {
public:
	Server() {
		context=zmq::context_t(1);
		std::thread tsend=std::thread(&Server::fsend, this);
		std::thread tsink=std::thread(&Server::fsink, this);
                tsend.join();
                tsink.join();
	}
private:
	zmq::context_t context;
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

	void fsink(){
		zmq::socket_t sockSink(context, ZMQ_PULL);
		sockSink.connect("tcp://127.0.0.1:5558");
		log("Sink: tcp://127.0.0.1:5558");
		while(1){
			zmq::message_t message;
			sockSink.recv(&message);
			std::string smessage=getString(&message);
			log("RECEIVED: "<<smessage);
			sleep(1);
		}

	}
	void fsend(){
		zmq::socket_t sockSend(context, ZMQ_PUSH);
		sockSend.bind("tcp://*:5557");
		log("Ventilator: tcp://127.0.0.1:5557");
		while(1) {
			std::string pkt=fmt::format("DATA:{}", randint(0, 256));
			sockSend.send(getMessage(pkt));
			log("SENT: "<<pkt);
			sleep(1);
		}
		log("Done.");
	}
};

int main(int argc, char *argv[]) {
	Server s;
	return 0;
}
