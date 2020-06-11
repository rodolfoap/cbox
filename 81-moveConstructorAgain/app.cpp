#include<iostream>
#define log(text) (std::cerr<<text<<std::endl)

void fn1(      int&  a) { std::cerr<<a<<std::endl; }
void fn2(const int&  a) { std::cerr<<a<<std::endl; }
void fn3(      int&& a) { std::cerr<<a<<std::endl; }

int main(){
	// error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	// fn1(3);
	// Why do we want this? because in case of a copy constructor, we want to move the rvalue
	// into the class without making a copy.

	// This works, but only because the signature includes a const:
	// fn2(const int& a)
	fn2(9);
	// Const is not useful in a copy-constructor because we want to steal the property and leave the
	// lvalue cannibalized.

	// Now, this works without the signature receiving a const, and because the signature refers to a temporary rvalue
	// fn3(int& a)
	fn3(13);
	// Using that, we can create an object and avoid copying, using a move-constructor instead
	// The particularity of a move constructor is that we can take the received value, use it in the copy
	// and destroy the original reference

	return 0;
}
