#include<iostream>

class Zero 	{
protected: 	int a;
public:		void setA(int);
		int getA() const;
		int getZero() const;
};

class Ones 	:public Zero {
public:		void doubleA();
};

void Zero::setA(int x)	{ a=x; }
int  Zero::getA() 	const // Members cannot be modified!
			{ return a; }
int  Zero::getZero()	const // Members cannot be modified!
			{ int z=0; return z; }
void Ones::doubleA()	{ a=a*2; }

int main(){
	Ones one;
	one.setA(13);
	std::cerr << one.getA() << std::endl;
	one.doubleA();
	std::cerr << one.getA() << std::endl;
}
// Class definitions always end in ";"
// Java: Class B extends A; C++: class B: public A; That is: lowercase, "extends" x ":public"
// Member definition: void ClassName::method();
// #include<iostream> to use std::cout
// int Clazz::method() const {...} : the 'const' keyword means that data members cannot be modified
// Classes have by default all members PRIVATE, while struct has all PUBLIC
