#include <string>
#include <map>

class Message{
private:
	std::string uuid;
	std::uint64_t timeNanos;
	std::string message;
	std::map<std::string, std::string> parms, optns;
public:
	Message(std::string message);
	std::string getJson();
	void addParam(std::string key, std::string val);
	void addOptns(std::string key, std::string val);
};
