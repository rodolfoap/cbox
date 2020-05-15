#include<iostream>

int main(){
	int ar[4];
	for(int i=0; i<4; i++) ar[i]=i;
	int* pt=ar;
	std::cerr<<ar<<std::endl;	// address ar
	std::cerr<<pt<<std::endl;	// same address
	std::cerr<<*pt<<std::endl;	// 0
	pt++;				// add the size of an integer
	std::cerr<<*pt<<std::endl;	// 1

	std::cerr<<*(pt+1)<<std::endl;	// 2
	std::cerr<<*(pt+2)<<std::endl;	// 3

	*(pt+2)=7;			// Change ar[3]=7
	std::cerr<<*(pt+2)<<std::endl;	// 7

	*((char*)pt+8)=65535;		// Change ar[3]=65535? (11111111 11111111) FALSE!
					// This is a pointer to char, so it will only replace
					// the first 8 bits (255), so ar[3]=255
	std::cerr<<*(pt+2)<<std::endl;	// 255 WRONG!

	*(int*)((char*)pt+8)=65535;	// Change ar[3]=65535
					// casting the pointer as char* requires an offset of 2*4=8;
					// in order to replace the int value, we need to cast back to int*
	std::cerr<<*(pt+2)<<std::endl;	// 65535 RIGHT!

	int ex[5];
	std::cerr<<sizeof(ex)<<std::endl;		// 20
	std::cerr<<sizeof(ex)/sizeof(int)<<std::endl;	// 5

	int* ep=new int[5];
	std::cerr<<sizeof(ep)<<std::endl;		// 8 (size of the pointer)

	return 0;
}
