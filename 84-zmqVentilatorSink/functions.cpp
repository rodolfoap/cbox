#include "functions.hpp"

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
std::string genuuid() {
	static uuid_t uuidObj;
	char charuuid[37];
	uuid_generate(uuidObj);
	uuid_unparse_lower(uuidObj, charuuid);
	return charuuid;
}
