#include <iostream>
#include <hello.hpp>
#include <hello_c.hpp>
#define log(t) std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"(): "<<t<<std::endl

int main(){
	char name[]="Thelonious";

	// Testing hello_c.cpp
	Hello *k=helloFactory();

	sayHello(k);
	printFloat(k, 17.19);
	std::cout<<"Double of 17: "<<doubleMe(k, 17)<<std::endl;
	std::cout<<sayHelloName(k, name)<<std::endl;
	delete k;
	std::cout<<std::endl;

	return 0;
}
