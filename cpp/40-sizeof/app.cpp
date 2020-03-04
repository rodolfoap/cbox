#include <iostream>

int main(){
	std::cerr
		<< "sizeof(char):        " << sizeof(char)		<< std::endl
		<< "sizeof(short):       " << sizeof(short)		<< std::endl
		<< "sizeof(int):         " << sizeof(int)		<< std::endl
		<< "sizeof(long):        " << sizeof(long)		<< std::endl
		<< "sizeof(long long):   " << sizeof(long long)		<< std::endl
		<< "sizeof(float):       " << sizeof(float)		<< std::endl
		<< "sizeof(double):      " << sizeof(double)		<< std::endl
		<< "sizeof(long double): " << sizeof(long double)	<< std::endl
		<< "sizeof(bool):        " << sizeof(bool)		<< std::endl;
	return(0);
}
