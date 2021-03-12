//
// Code for external functions
//

#include <iostream>
#include <hello.hpp>
#include <hello_c.hpp>

extern "C" {
	// Factory
	Hello* helloFactory() {
		return new Hello();
	}
	// Takes the object as argument
	void sayHello(Hello* hello) {
		hello->sayHello();
	}
	// Takes the object and a double as argument
	void printFloat(Hello* hello, double input) {
		return hello->printFloat(input);
	}
	// Takes the object and an integer as argument
	int doubleMe(Hello* hello, int input) {
		return hello->doubleMe(input);
	}
	// Takes the object and a char array
	const char *sayHelloName(Hello* hello, char* name){
		return hello->sayHelloName(name);
	}
}
