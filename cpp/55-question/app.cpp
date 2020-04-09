#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(){
	int a=2;
	a=7+a++; //same as a+++7;
	// The operation happens as this:
	// lvalue=2, rvalue=7+2++ Start
	// lvalue=2, rvalue=9++   Operations
	// lvalue=9, rvalue=9++   Assignation
	// lvalue=9, rvalue=10    Postincrement
	std::cerr<<a<<std::endl;  // shows 9
	return 0;
}
