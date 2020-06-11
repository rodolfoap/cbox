#include<iostream>
#define log(text) (std::cerr<<text<<std::endl)

void fn1(      int&  a) { std::cerr<<a<<std::endl; }
void fn2(const int&  a) { std::cerr<<a<<std::endl; }
void fn3(      int&& a) { std::cerr<<a<<std::endl; }

struct Integer{ int n;
	Integer(int n):n(n)            { log("Integer-Constructor"      ); }
	Integer(const Integer& other)  { log("Integer-Copy-Constructor" ); } };
struct Klazz1{ Integer i; Klazz1(Integer j): i(j) {} }; // (2)

struct Integer2{ int n;
	Integer2(int n):n(n)           { log("Integer2-Constructor"     ); }
	Integer2(Integer2&& other)     { log("Integer2-Move-Constructor"); } };
struct Klazz2{ Integer2 i; Klazz2(Integer2&& j): i((Integer2&&)j) { } }; // (3)

int main(){
	// error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	// fn1(3);
	// Why do we want this? because in case of a copy constructor, we want to move the rvalue
	// into the class without making a copy.
	Klazz1 k(Integer(3)); // runs Integer-Constructor, then in (2) runs Integer-Copy-Constructor.

	// This works, but only because the signature includes a const:
	// fn2(const int& a)
	fn2(3);
	// Const is not useful in a copy-constructor because we want to steal the property and leave the
	// lvalue unreferenced.

	// Now, this works without the signature receiving a const, and because the signature refers to a temporary rvalue
	// fn3(int& a)
	fn3(3);
	// Using that, we can create an object and avoid copying, using a move-constructor instead:
	Klazz2 p(Integer2(3)); // runs Integer2-Constructor, then in (3) runs Integer2-Move-Constructor.

	return 0;
}
