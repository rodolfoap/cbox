#include <iostream>
#include <cstring>
#include <holder.hpp>
#include <secbroker.hpp>

extern "C" {

	secbroker *create(int32_t width, const char *name) {
		secbroker *holder=new secbroker();
		holder->width=width;
		holder->name=name;
		return holder;
	}

	void display(secbroker *holder, const char *message) {
		if(holder) holder->print(message);
		else std::cerr<<"holder==nullptr"<<std::endl;
	}

	void modify(secbroker *holder, const char *name, uint32_t x) {
		holder->name=name;
		holder->width=x;
	}

	void destroy(secbroker **holder) {
		if(*holder !=nullptr) {
			delete(*holder);
			*holder=nullptr;
		}
	}
}
