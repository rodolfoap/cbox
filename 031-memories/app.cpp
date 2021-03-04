#include<iostream>

//int global=255;
char global[]="text";

int main(){
	//int stack=255;
	char stack[]="text";

	int* heap=new int;
	*heap=255;

	const char* code="text";

	int* codi;

	printf("GLOBAL: global[%p]\n", &global);
	printf(" STACK:  stack[%p]\n", &stack);
	printf("  HEAP:   heap[%p]\n", heap);
	printf("  CODE:   code[%p]\n", code);
	printf("  CODE:   codi[%p]\n", codi);
	return 0;
}
