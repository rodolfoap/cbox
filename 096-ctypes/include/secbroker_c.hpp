#include <secbroker.hpp>

extern "C" {
	SecBroker *create(const char*, uint32_t);
	void display(SecBroker*, const char*);
	void modify(SecBroker*, const char*, uint32_t);
	void destroy(SecBroker**);
}
