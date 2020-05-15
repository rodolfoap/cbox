#include<iostream>

void passByValue(int    x){   x=3; printf("(int x[%p]==%d); ",  &x,    x);} // x is received
void passByRefer(int&   x){   x=2; printf("(int x[%p]==%d); ",  &x,    x);} // x is an alias
void passPointer(int*   p){  *p=1; printf("(int x[%p]==%d); ",   p,   *p);} // p is a pointer
void passPtr2Ptr(int**  p){ **p=9; printf("(int x[%p]==%d); ",  *p,  **p);} // p is a pointer to pointer
void passPtr2P2P(int*** p){***p=7; printf("(int x[%p]==%d); ", **p, ***p);} // p is a pointer to pointer to pointer

int main (){
	// A simple variable
	int a=4;

	/* A simple reference; but this is forbidden:

	int& b;
	b = a;
	.../app.cpp:9:7: error: ‘b’ declared as reference but not initialized

        So, references must be initialized after declared: */
	int& b=a;

	passByValue( b);	std::cerr<< a <<std::endl; // 4
	passByRefer( b);	std::cerr<< a <<std::endl; // 2
	passPointer(&b);	std::cerr<< a <<std::endl; // 1

	// Now, a pointer to pointer:
	a=4;
	int* c;
	c=&a;
	passPointer(c);		std::cerr<< a <<std::endl; // 1

	a=4;
	int*  pa=&a;
	int** pb=&pa;
	passPtr2Ptr(pb);	std::cerr<< a <<std::endl; // 9

	// Now, a pointer to pointer to pointer:
	int*** pc=&pb;
	passPtr2P2P(pc);	std::cerr<< a <<std::endl; // 7
}
// Pass ByValue:     void run(int  x){} ... run(a)  ... does not change value
// Pass ByReference: void run(int &x){} ... run(a)  ... changes value
// Pass Pointer:     void run(int *x){} ... run(&a) ... changes value
// Pass ByVal and ByRef are called without modifiers: run(a);
//      byRef ONLY changes reception; is called run(a), received (run int &x) and used x++;
// Pass Pointer changes calling: run(&a); receiving: run(int* x); using: *x++;
