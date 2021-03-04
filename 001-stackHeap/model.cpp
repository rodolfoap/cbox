#include<iostream>
#include"print.h"

struct Point{
	float x, y, z;
	Point() :x(9), y(9), z(9){};
};

int main(){
	int svalue=9;
	print(svalue);

	int* hvalue=new int;
	*hvalue=9;
	print(*hvalue);

	int sarray[9]={9, 8, 7, 6, 5, 4, 3, 2, 1};
	print(sarray[0]);

	int* harray=new int[9];
	harray[0]=9;
	print(harray[0]);

	Point spoint;
	print(spoint.x);

	Point* hpoint=new Point();
	print(hpoint->x);

	return 0;
}
