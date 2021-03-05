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
	void printfloat(Hello* hello, double input) {
		return hello->printfloat(input);
	}
	// Takes the object and an integer as argument
	int doubleme(Hello* hello, int input) {
		return hello->doubleme(input);
	}
	/*
	const char *sayHelloName(Hello* hello, char* name){
		return hello->sayHelloName(name);
	}
	*/
}
