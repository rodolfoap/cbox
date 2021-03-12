#include <secbroker_c.hpp>

extern "C" {
	SecBroker *create(int32_t width, const char *name) {
		SecBroker *secbroker=new SecBroker();
		secbroker->width=width;
		secbroker->name=name;
		return secbroker;
	}

	void display(SecBroker *secbroker, const char *message) {
		if(secbroker) secbroker->print(message);
		else std::cerr<<"secbroker==nullptr"<<std::endl;
	}

	void modify(SecBroker *secbroker, const char *name, uint32_t x) {
		secbroker->name=name;
		secbroker->width=x;
	}

	void destroy(SecBroker **secbroker) {
		if(*secbroker !=nullptr) {
			delete(*secbroker);
			*secbroker=nullptr;
		}
	}
}
