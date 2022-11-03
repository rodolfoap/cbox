#include<string.h>

void reverse(char* n, char* r) {
	// sizeof(n) returns 	64;
	// strlen(n) returns 	4 [j,o,h,n,\0] (does not count the \0)
	int l=strlen(n); 	// 4

	r[l]=0;			// ____0
	for(int i=0; i<l; i++)
		r[l-1-i]=n[i];	// r[3]=n[0]... etc.
}
