#include<iostream>
#include<memory>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl

class E{
public:
	E(){ std::cerr<<"\tconstructor"<<std::endl; }
	~E(){ std::cerr<<"\tdestructor"<<std::endl; }
	void fn(){ std::cerr<<"\tfunct"<<std::endl; }
};

int main(){
	// Without smart pointer:
	E* e=new E();
	e->fn();
	std::cerr<<"Will call destructor:"<<std::endl;
	delete e;

	std::cerr<<"SCOPE-0"<<std::endl;
	{
		std::unique_ptr<E> e(new E());
		e->fn(); // No need to delete: will do when exiting scope
	}
	std::cerr<<"SCOPE-0"<<std::endl;
	{
		std::unique_ptr<E> e3 = std::make_unique<E>();
		e3->fn(); // No need to delete: will do when exiting scope
	}
	std::cerr<<"SCOPE-0"<<std::endl;
	return 0;
}
