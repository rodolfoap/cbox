#include <iostream>
#include <cstring>

extern "C" {
	class secbroker {
	public:
		int32_t width;
		std::string name="-";
		void print(std::string);
	};

	secbroker *create(int32_t width, const char *name);
	void display(secbroker *holder, const char *message);
	void modify(secbroker *holder, const char *name, uint32_t x);
	void destroy(secbroker **holder);
}