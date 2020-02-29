#include <iostream>
#include <stdio.h>

class Singleton {
public:
	static Singleton& getInstance(){ return instance; }
private:
	Singleton() {}
	Singleton(Singleton&) {}
	static Singleton instance;
};
Singleton Singleton::instance;

int main() {
	Singleton sing1 = Singleton::getInstance();
	Singleton sing2 = Singleton::getInstance();
	/* Singleton addresses should be the same! */
	std::cerr << &sing1 << std::endl;
	std::cerr << &sing2 << std::endl;
}
