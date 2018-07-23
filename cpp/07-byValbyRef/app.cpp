#include<iostream>

void passByValue(int  x){ x=3; printf("(int x[%p]==%d); ", &x,  x);} // x is received
void passByRefer(int &x){ x=2; printf("(int x[%p]==%d); ", &x,  x);} // x is received too: this is IDENTIC!
void passPointer(int *p){*p=1; printf("(int x[%p]==%d); ",  p, *p);} // p is a pointer

int main (){
	int a = 4;
	passByValue( a);	std::cerr<< a <<std::endl; // 4
	passByRefer( a);	std::cerr<< a <<std::endl; // 2
	passPointer(&a);	std::cerr<< a <<std::endl; // 1
}
// Pass ByValue:     void run(int  x){} ... run(a)  ... does not change value
// Pass ByReference: void run(int &x){} ... run(a)  ... changes value
// Pass Pointer:     void run(int *x){} ... run(&a) ... changes value
// Pass ByVal and ByRef are called without modifiers: run(a); //byRef ONLY changes reception; is called run(a), received (run int &x) and used x++;
// Pass Pointer changes calling: run(&a); receiving: run(int* x); using: *x++;
