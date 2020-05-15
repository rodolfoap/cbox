#include <iostream>
#include <bitset>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

template<typename T> std::bitset <8>  get8bin(T code){ return std::bitset< 8>(code); }
template<typename T> std::bitset<32> get32bin(T code){ return std::bitset<32>(code); }
int main(){
	char c=-1; // 0b11111111
	std::cerr<<"c: 0b"<< get8bin(c)<<':'<<+c<<std::endl;
	std::cerr<<"c: 0b"<<get32bin(c)<<':'<<+c<<std::endl;

	// Putting 4 bytes (an int) inside 1 byte (a char) corrupts the stack:	[1]
	int *p;
	p=(int*)&c;
	*p=0b10101010101010101010101010101010;
	std::cerr<<"p: 0b"<<get32bin(*p)<<':'<<+(*p)<<std::endl;
	std::cerr<<"c: 0b"<< get8bin(c) <<':'<<  +c <<std::endl;

	// Static cast checks errors only at compile time. This is an error:
	// error: invalid static_cast from type ‘char*’ to type ‘int*’
	// int *q=static_cast<int*>(&c);

	// Naturally, this would work:
	int  i=-1; // 0b11111111111111111111111111111111
	std::cerr<<"i: 0b"<<get32bin(i)<<':'<<+i<<std::endl;
	float f=static_cast<float>(i);
	std::cerr<<"f: 0b"<<get32bin(f)<<':'<<+f<<std::endl;

	// The way to force the conversion in [1] is using reinterpret_cast:
	int *r=reinterpret_cast<int*>(&c);
	std::cerr<<"r: 0b"<<get32bin(*r)<<':'<<+(*r)<<std::endl;

	// Now, dynamic casting checks for runtime errors, and can only check
	// for polymorphism derivation. This will work:

	struct BaseClass{
		virtual void function1() { std::cerr<<'f'<<std::endl; }
	};
	struct DerivedClass:public BaseClass {
		void function1() { std::cerr<<'g'<<std::endl; }
	};

	DerivedClass *drvd=new DerivedClass();
	drvd->function1(); // prints 'g'
	BaseClass    *base=dynamic_cast<BaseClass*>(drvd);
	base->function1(); // prints 'g'

	return 0;
}
