#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

static class Counter{
public:
	void print(){
		std::cerr<<"Hello, World!"<<std::endl;
	}
} c; // Not a static class, but a static object

int main(){
	// A quite silly example...
	c.print();
	return 0;
}
