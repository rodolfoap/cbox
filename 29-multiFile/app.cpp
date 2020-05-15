#include<iostream>
#include "Solid.h"

int main(){
	Solid solid;
	solid.setName("solid0");
	std::cerr << solid.getName() << std::endl;
	return 0;
}
