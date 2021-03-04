#include <iostream>

class Singleton {
public:
	// Returns a C++ reference:
	static Singleton& getInstance(){
		static Singleton instance;
		return instance;
	}
	// C++11 allows deleting methods, better than non
	// implementing them:
	// 	Singleton(const Singleton&);
	// 	void operator=(const Singleton&);
	Singleton(const Singleton&)=delete;
	void operator=(const Singleton&)=delete;

	// Some method...
	void getAddress(){
		std::cerr<<&getInstance()<<std::endl;
	}
private:
	// Mark constructor as private:
	Singleton() {}
};

int main() {
	Singleton& sing1=Singleton::getInstance();
	Singleton& sing2=Singleton::getInstance();

	sing1.getInstance();
	sing2.getInstance();
	sing1.getInstance().getAddress();
	sing2.getInstance().getAddress();
}
