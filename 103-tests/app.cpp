#include<iostream>
#include<string.h>
#include "reverse.hpp"

int main(){
	char n[5]="john", r[5]={};
	reverse(n, r);
	std::cout<<n<<std::endl<<r<<std::endl;

	char n2[101]="happen upon truth by a trick of the eye, if the truth falsehood of the resulting belief is important";
	char r2[101]={};
	reverse(n2, r2);
	std::cout<<n2<<std::endl<<r2<<std::endl;

	return 0;
}
