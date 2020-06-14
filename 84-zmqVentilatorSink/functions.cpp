#include <zmq.hpp>
#include <string>

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
