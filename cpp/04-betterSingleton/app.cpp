#include <iostream>

class Singleton {
public:
	static Singleton& getInstance(){
		std::cout << "getInstance()" << std::endl;
		static Singleton instance;
		return instance;
	}
	void hello(){
		// Let's show the address
		std::cout << "ADDRESS: " << &getInstance() << std::endl;
	}
private:
	Singleton(Singleton const&); // Don't Implement.
	void operator=(Singleton const&); // Don't implement
	Singleton() {
		std::cout << "Constructor" << std::endl;
	}
};


int main() {
	Singleton& singleton1=Singleton::getInstance();
	Singleton& singleton2=Singleton::getInstance();

	// Addresses should be the same
	std::cout << &singleton1 << std::endl;
	std::cout << &singleton2 << std::endl;

	// Example calls
	singleton1.hello();
	singleton2.hello();
	singleton2.hello();
}
