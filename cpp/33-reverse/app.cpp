#include<iostream>
#include<string.h>

int main(){
	char n[64], r[64];
	std::cout<<"Name: ";
	std::cin>>n;		// john

	// sizeof(n) returns 	64;
	// strlen(n) returns 	4 [j,o,h,n,\0] (does not count the \0)
	int l=strlen(n); 	// 4

	r[l]=0;			// ____0
	for(int i=0; i<l; i++)
		r[l-1-i]=n[i];	// r[3]=n[0]... etc.
	std::cout<<n<<std::endl<<r<<std::endl;
	return 0;
}
