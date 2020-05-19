#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

template<unsigned int n> struct factorial {
	enum {value=n*factorial<n-1>::value};
};
template<> struct factorial<0> {
	enum {value=1};
};

int main() {
	std::cerr<<factorial<5>::value<<std::endl;
}
