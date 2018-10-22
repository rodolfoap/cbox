#include <iostream>

class Foo{
public:
	void bar(){
		std::cerr << "Hello, World!\n";
	}
};

extern "C" {
	Foo* Foo_new(){
		return new Foo();
	}
	void Foo_bar(Foo* foo){
		foo->bar();
	}
}
