#include "functions.hpp"

zmq::message_t getMessage(std::string s) {
	encryptDecrypt(s);
	int length=s.length();
	zmq::message_t message(length);
	memcpy(message.data(), s.c_str(), length);
	return message;
}
std::string getString(zmq::message_t* m) {
	std::string s(static_cast<char*>(m->data()), (m->size()));
	encryptDecrypt(s);
	return s;
}
std::string genuuid() {
	static uuid_t uuidObj;
	char charuuid[37];
	uuid_generate(uuidObj);
	uuid_unparse_lower(uuidObj, charuuid);
	return charuuid;
}
void encryptDecrypt(std::string& m) {
	char key[]="gtd-international.com";
	for(int i=0; i<m.size(); i++)
	m[i] = m[i]^key[i%(sizeof(key)/sizeof(char))];
}
