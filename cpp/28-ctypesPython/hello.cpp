#include <iostream>

class Hello{
public:
	void sayHello(){
		std::cerr << "Hello, World!\n";
	}
};

extern "C" {
	Hello* getHello(){
		return new Hello();
	}
	void sayHello(Hello* hello){
		hello->sayHello();
	}
}

// See https://stackoverflow.com/questions/145270/calling-c-c-from-python
