#include <iostream>
#include <hello.hpp>
#include <hello_c.hpp>
#define log(t) std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"(): "<<t<<std::endl

int main(){
	Hello* k=helloFactory();

	k->sayHello();
	k->printfloat(19.17);
	std::cout<<"Double of 19: "<<k->doubleme(19)<<std::endl;

	delete k;
	return 0;
}
