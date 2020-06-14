#include <zmq.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fmt/format.h>
#include <uuid/uuid.h>
#include <time.h>
#include "json.hpp"
#include "functions.cpp"
#define randomf(n1, n2) (((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

struct Message{
	std::string uuid;
	std::uint64_t timeNanos;
	std::string command;
	std::vector<std::pair<std::string, std::string>> parameters, options;
	Message(std::string command):
		uuid(genuuid()), command(command),
		timeNanos(std::chrono::duration_cast<std::chrono::nanoseconds>
			 (std::chrono::system_clock::now().time_since_epoch()).count()) {}
	std::string genuuid() {
		static uuid_t uuidObj;
		char charuuid[37];
		uuid_generate(uuidObj);
		uuid_unparse_lower(uuidObj, charuuid);
		return charuuid;
	}
	void addParameters(std::string key, std::string val){
		parameters.push_back(std::pair<std::string, std::string>(key, val));
	}
	void addOptions(std::string key, std::string val){
		options.push_back(std::pair<std::string, std::string>(key, val));
	}
	std::string getJson(){
		nlohmann::json j={ {"uuid", uuid}, {"timenanos", timeNanos}, {"command", command} };
		for(auto p: parameters){ j["parameters"][p.first]=p.second; }
		for(auto p:    options){ j[   "options"][p.first]=p.second; }
		return j.dump();
	}
};

class Server {
public:
	Server() {
		Message m("raisealert");
		m.addParameters("text", "Hello, World");
		m.addParameters("priority", "0");
		m.addOptions   ("requireack", "true");
		log("Message:"<<m.getJson());
		std::thread tsend=std::thread(&Server::fsend, this);
		std::thread tsink=std::thread(&Server::fsink, this);
                tsend.join();
                tsink.join();
	}
private:
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
