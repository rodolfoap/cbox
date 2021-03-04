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
LOG
	{
		std::shared_ptr<E> e1;
LOG
		{
LOG
			std::shared_ptr<E> e2=std::make_shared<E>();
			// Only one pointer referencing the object
			std::cerr<<"\tuse_count:"<<e2.use_count()<<std::endl;

			e1=e2;
			// Now, TWO pointers referencing the object
			std::cerr<<"\tuse_count:"<<e2.use_count()<<std::endl;
			// Another pointer to the same object
			std::cerr<<"\tuse_count:"<<e1.use_count()<<std::endl;
		// Exiting the scope will remove ONE reference:
		}
LOG
		std::cerr<<"\tuse_count:"<<e1.use_count()<<std::endl;
		if (e1) { e1->fn(); }
LOG
	}
LOG	// Using auto:
	{
		auto e=std::make_shared<E>();
		e->fn();
	}
LOG
	return 0;
}
