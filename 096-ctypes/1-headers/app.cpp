#include <iostream>
#include <hello.hpp>
#include <hello_c.hpp>
#define log(t) std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"(): "<<t<<std::endl

int main(){
	char name[]="Thelonious";

	// Testing hello.cpp
	Hello *k=new Hello();

	k->sayHello();
	k->printFloat(19.17);
	std::cout<<"Double of 19: "<<k->doubleMe(19)<<std::endl;
	std::cout<<k->sayHelloName(name)<<std::endl;
	delete k;
	std::cout<<std::endl;

	// Testing hello_c.cpp
	Hello *c=helloFactory();
	sayHello(c);
	printFloat(c, 17.19);
	std::cout<<"Double of 17: "<<doubleMe(c, 17)<<std::endl;
	std::cout<<sayHelloName(c, name)<<std::endl;
	delete c;
	std::cout<<std::endl;

	return 0;
}
