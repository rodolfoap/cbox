#include <secbroker.hpp>

extern "C" {
	SecBroker *create(int32_t width, const char *name);
	void display(SecBroker *holder, const char *message);
	void modify(SecBroker *holder, const char *name, uint32_t x);
	void destroy(SecBroker **holder);
}
