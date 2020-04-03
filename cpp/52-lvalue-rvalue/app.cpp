#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int& getValue(){ static int x; return x; }
void example1(){
	// Since the function returns an lvalue, it can be set and it can be get.
	getValue()=5;
	std::cerr<<getValue()<<std::endl;
}

void lprint(      int&  x){ std::cerr<<x<<std::endl; }
void tprint(const int&  x){ std::cerr<<x<<std::endl; }
void rprint(      int&& x){ std::cerr<<x<<std::endl; }
void example2(){
	int a=9;
	int b=8;
	int c=a+b;
	// lvalue print: takes a reference;
	lprint(c);
	// rvalue print: takes a reference,
	// accepted if it is const;
	tprint(a+b+2);
	// rvalue print: takes a reference to a reference;
	rprint(a+b+2);
}

int main(){
	example1();
	example2();
	return 0;
}
