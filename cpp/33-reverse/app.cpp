#include<iostream>
#include<string.h>

int main(){
	char n[50], r[50];
	std::cout<<"Name: ";
	std::cin>>n;		// Example: john
	size_t l=strlen(n); 	// 4(+1)
	r[l]=0;			// ____0
	for(size_t i=0; i<l; i++) r[l-1-i]=n[i];
	std::cout<<r<<"["<<l<<"]"<<std::endl;
	return 0;
}
