#include<iostream>
#include<string.h>
#include "reverse.hpp"

int main(){
	char n[5]="john", r[5]={};
	reverse(n, r);
	std::cout<<n<<std::endl<<r<<std::endl;
	return 0;
}
