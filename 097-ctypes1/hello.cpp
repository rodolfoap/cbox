#include <iostream>

class Hello {
public:
	void sayHello() {
		std::cerr<<"Hello, World!\n";
	}
	int doubleme(int input) {
		return 2 * input;
	}
	void printfloat(double input) {
		std::cout<<"printFloat(): "<<input<<std::endl;
	}
};

extern "C" {
	// Factory
	Hello* helloFactory() {
		return new Hello();
	}
	// Takes the object as argument
	void sayHello(Hello* hello) {
		hello->sayHello();
	}
	// Takes the object and an integer as argument
	int doubleme(Hello* hello, int input) {
		return hello->doubleme(input);
	}
	// Takes the object and a double as argument
	void printfloat(Hello* hello, double input) {
		return hello->printfloat(input);
	}
}
