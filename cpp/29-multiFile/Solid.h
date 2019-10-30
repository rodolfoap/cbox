#include<iostream>
#include "Thing.h"

class Solid :public Thing{
public:
	std::string getName() const;
	void setName(std::string);
};
