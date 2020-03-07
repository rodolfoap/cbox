#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class Line{
public:
	void print(){ std::cerr<<"Line."<<std::endl; }

};
int main(){
	// Simple stack initialization
	Line x;
	x.print();

	// Using a pointer:
	Line* p1=&x;

	// p1.print() has no sense, p1 is a pointer, has no methods.
	// So, we can dereference it (object-pointed-dot-print will work).
	(*p1).print();

	// This means the same:
	p1->print();
	return 0;
}
