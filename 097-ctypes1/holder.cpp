#include <iostream>
#include <cstring>
#include <holder.hpp>

HOLDER *create(int32_t width, const char *fname) {
	std::cerr<<"create(): "<<fname<<std::endl;
	HOLDER *holder=new HOLDER();
	holder->width=width;
	strcpy(holder->name, fname);
	return holder;
}

void modify(HOLDER *holder, const char *fname, uint32_t x) {
	if(holder) std::cerr<<"PRE/modify(): "<<holder->width<<"; "<<holder->name<<std::endl;
	strcpy(holder->name, fname);
	holder->width=x;
	if(holder) std::cerr<<"POST/modify(): "<<holder->width<<"; "<<holder->name<<std::endl;
}

void destroy(HOLDER **holder) {
	if(*holder !=nullptr) {
		std::cerr<<"destroy(): "<<(*holder)->name<<std::endl;
		delete(*holder);
		*holder=nullptr;
	}
}
