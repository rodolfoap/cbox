#include <string>
#include <chrono>
#include <time.h>
#include "json.hpp"
#include "functions.hpp"
#include "message.hpp"

Message::Message(std::string command):
	uuid(genuuid()), command(command),
	timeNanos(std::chrono::duration_cast<std::chrono::nanoseconds>
		 (std::chrono::system_clock::now().time_since_epoch()).count()) {}
void Message::addParam(std::string key, std::string val){ parms.insert({key, val}); }
void Message::setParam(std::string key, std::string val){ parms.at(key)=val; }
void Message::addOptns(std::string key, std::string val){ optns.insert({key, val}); }
std::string Message::getJson(){
	nlohmann::json j={ {"uuid", uuid}, {"timenanos", timeNanos}, {"command", command} };
	for(auto& p: parms){ j["parameters"][p.first]=p.second; }
	for(auto& p: optns){ j["options"][p.first]=p.second; }
	return j.dump();
}
