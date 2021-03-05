#include <iostream>
#include <hello.hpp>
#define log(t) std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"(): "<<t<<std::endl

int main(){
	Hello h;
	h.sayHello();
//	Hello* k=helloFactory();
	return 0;
}
