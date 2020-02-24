#include<iostream>

int main(){
	int a=22;
	int* b=&a;
	std::cerr << *b << std::endl; // 22

	char c[]="text";
	char *d=c;
	printf("PTR: c:%p, d:%p\n", c, d);
	printf("ADR: c:%p, d:%p\n", &c, &d);
	printf("STR: c:%s, d:%s\n", c, d);
	std::cerr << d << std::endl; // 22
	return 0;
}
