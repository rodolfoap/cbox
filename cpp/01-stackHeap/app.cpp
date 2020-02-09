#include<iostream>
#include"print.h"

struct Point{
	float x, y, z;
	// Initializer lists begin with a colon, then
	// all the members with its values
	Point() :x(9), y(9), z(9){};
};

int main(){
	// The variable goes to the stack
	int svalue=9;
	print(svalue);

	// The variable goes to the heap
	int* hvalue=new int;
	*hvalue=9;
	print(*hvalue);

	// The variable goes to the stack
	int sarray[9]={9, 8, 7, 6, 5, 4, 3, 2, 1};
	print(sarray[0]);

	// The variable goes to the heap
	int* harray=new int[9];
	harray[0]=9;
	print(harray[0]);

	// The variable goes to the stack
	Point spoint;
	// The dot operator (.) is used if the variable
	// accesses a member
	print(spoint.x);

	// The variable goes to the heap
	Point* hpoint=new Point();
	// arrow operator (->) is used if the variable accesses 
	// a member of a pointer
	print(hpoint->x);

	return 0;
}
