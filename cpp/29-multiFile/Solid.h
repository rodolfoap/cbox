#include<iostream>
#include "Thing.h"

#ifndef _SOLID
#define _SOLID
class Solid :public Thing{
public:
	std::string getName() const;
	void setName(std::string);
};
#endif
