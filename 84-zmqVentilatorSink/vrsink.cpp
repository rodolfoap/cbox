#include <zmq.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <uuid/uuid.h>
#include <fmt/format.h>
#include <time.h>
#include "json.hpp"
#include "functions.cpp"
#define randomf(n1, n2) (((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

class Message{
private:
	std::string uuid;
	std::uint64_t timeNanos;
	std::string command;
	std::map<std::string, std::string> parms, optns;
public:
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
	void addParam(std::string key, std::string val){ parms.insert({key, val}); }
	void setParam(std::string key, std::string val){ parms.at(key)=val; }
	void addOptns(std::string key, std::string val){ optns.insert({key, val}); }
	std::string getJson(){
		nlohmann::json j={ {"uuid", uuid}, {"timenanos", timeNanos}, {"command", command} };
		for(auto& p: parms){ j["parameters"][p.first]=p.second; }
		for(auto& p: optns){ j["options"][p.first]=p.second; }
		return j.dump();
	}
};

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
			m.setParam("text", fmt::format("Collapsing probability is: {}", randomf(0, 1)));
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
