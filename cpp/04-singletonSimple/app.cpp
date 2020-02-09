#include <iostream>

class Singleton {
private:
	static Singleton* instance;
	Singleton() {}

public:
	static Singleton* getInstance(){
		if (instance == 0) { instance = new Singleton(); }
		return instance;
	}
};
Singleton* Singleton::instance=0;

int main() {
	Singleton* sing1 = Singleton::getInstance();
	Singleton* sing2 = Singleton::getInstance();
	/* Singleton addresses should be the same! */
	std::cout << sing1 << std::endl;
	std::cout << sing2 << std::endl;
}
