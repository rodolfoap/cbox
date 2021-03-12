#include <secbroker_c.hpp>

extern "C" {
	SecBroker *create(const char *name, uint32_t size) {
		SecBroker *secbroker=new SecBroker();
		secbroker->name=name;
		secbroker->size=size;
		return secbroker;
	}

	void display(SecBroker *secbroker, const char *message) {
		if(secbroker) secbroker->print(message);
		else std::cerr<<"secbroker==nullptr"<<std::endl;
	}

	void modify(SecBroker *secbroker, const char *name, uint32_t size) {
		secbroker->name=name;
		secbroker->size=size;
	}

	void destroy(SecBroker **secbroker) {
		if(*secbroker !=nullptr) {
			delete(*secbroker);
			*secbroker=nullptr;
		}
	}
}
