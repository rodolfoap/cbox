#include<iostream>

int main(){
	int ar[3];
	for(int i=0; i<3; i++) ar[i]=i;
	int* pt=ar;
	std::cerr<<ar<<std::endl;	// address ar
	std::cerr<<pt<<std::endl;	// same address
	std::cerr<<*pt<<std::endl;	// 0
	pt++;				// add the size of an integer
	char* pc=(char*)pt;
	std::cerr<<*pt<<std::endl;	// 1
	pc=pc+4;
	std::cerr<<*pt<<std::endl;	// 1

	return 0;
}
