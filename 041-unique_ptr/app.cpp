#include<iostream>
#include<memory>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class E{
public:
	E(){ std::cerr<<"\tconstructor"<<std::endl; }
	~E(){ std::cerr<<"\tdestructor"<<std::endl; }
	void fn(){ std::cerr<<"\tfn"<<std::endl; }
};

int main(){
LOG	// Without smart pointer:
	E* e=new E();
	e->fn();
	delete e;

LOG	// Using smart pointers:
	{
		std::unique_ptr<E> e(new E()); // Do not use new!!
		e->fn(); // No need to delete: will do when exiting scope
	}
LOG 	// Using make-unique (C++14!)
	{
		std::unique_ptr<E> e=std::make_unique<E>();
		e->fn();
	}
LOG 	// Better:
	{
		auto e=std::make_unique<E>();
		e->fn();
	}
LOG
	return 0;
}
