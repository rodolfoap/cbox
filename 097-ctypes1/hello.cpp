//
// Code for a simple class
//

#include <iostream>
#include <hello.hpp>
#include <hello_c.hpp>

void Hello::sayHello() {
	std::cerr<<"Hello, World!\n";
}
void Hello::printFloat(double input) {
	std::cout<<"printFloat(): "<<input<<std::endl;
}
int Hello::doubleme(int input) {
	return 2 * input;
}
const char* Hello::sayHelloName(char* name){
	static std::string s="Hello, ";
	s+=name;
	return s.c_str();
}
