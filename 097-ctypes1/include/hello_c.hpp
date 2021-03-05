#include <iostream>

extern "C" {
	// Factory
	Hello* helloFactory();
	// Takes the object as argument
	void sayHello(Hello* hello);
	// Takes the object and a double as argument
	void printfloat(Hello* hello, double input);
	// Takes the object and an integer as argument
	int doubleme(Hello* hello, int input);
	// Strings management
	// const char *sayHelloName(Hello* hello, char* name);
}
