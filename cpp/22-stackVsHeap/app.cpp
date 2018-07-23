#include<iostream>

struct Thing{
	float x, y, z;
};

int main(){

	// Stack

	int svalue=7;
	std::cerr <<  svalue << std::endl;

	int sarray[2];
	sarray[1]=97;
	std::cerr << sarray[1] << std::endl;

	Thing sthing;
	sthing.z=49;
	std::cerr << sthing.z << std::endl;

	// Heap

	//int* hvalue=new int;
	int* hvalue=(int*)malloc(sizeof(int));
	*hvalue=9;
	std::cerr << *hvalue << std::endl;
	free(hvalue);
	// hvalue is a dangling pointer
	hvalue=NULL;
	// not anymore!

	// Equivalent to:
	int* harray=(int*)malloc(2*sizeof(int));
	// int* harray=new int[2];
	harray[1]=91;
	std::cerr << harray[1] << std::endl;
	free(harray);
	// harray is a dangling pointer
	harray=NULL;
	// not anymore!

	Thing* hthing=new Thing();
	hthing->z=57;
	std::cerr << hthing->z << std::endl;

	return 0;
}
