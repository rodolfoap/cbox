#include <helloworld.hpp>
#include <iostream>

HelloWorld::HelloWorld(){}

int HelloWorld::say() {
	std::cerr<<"Hello, World!"<<std::endl;
	return 0;
}
