#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

// Static classes there are no in C++. A class is called static when
// all its members are static, as in the following example:
class Counter{
public:
	static int count;
	static void add(){
		count++;
	}
	static void print(){
		std::cerr<<"Count: "<<count<<std::endl;
	}
};

// Static class members need to be initialized.
int Counter::count=0;

int main(){
	Counter::print();
	Counter::add();
	Counter::add();
	Counter::print();
	return 0;
}
