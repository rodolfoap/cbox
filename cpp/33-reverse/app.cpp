#include<iostream>
#include<string.h>

int main(){
	char n[50], r[50];
	std::cout<<"Name: ";
	std::cin>>n;		// john
	int l=strlen(n); 	// 4 (without \0)
	r[l]=0;			// ____0
	for(int i=0; i<l; i++)
		r[l-1-i]=n[i];	// r[3]=n[0]... etc.
	std::cout<<r<<std::endl;
	return 0;
}
