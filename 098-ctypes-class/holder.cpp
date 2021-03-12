#include <iostream>
#include <cstring>

extern "C" {
	class secbroker {
	public:
		int32_t width;
		std::string name="-";
		void print(std::string label){ std::cerr<<label<<"::print(): "<<name<<"/"<<width<<std::endl; }
	};

	secbroker *create(int32_t width, const char *fname) {
		secbroker *holder=new secbroker();
		holder->width=width;
		holder->name=fname;
		return holder;
	}

	void print(secbroker *holder, const char *message) {
		if(holder) holder->print(message);
	}

	void modify(secbroker *holder, const char *fname, uint32_t x) {
		holder->name=fname;
		holder->width=x;
	}

	void destroy(secbroker **holder) {
		if(*holder !=nullptr) {
			delete(*holder);
			*holder=nullptr;
		}
	}
}
