#include <iostream>

class Thing{
protected:
	std::string name;
};

class Solid :public Thing{
public:
	std::string getName();
	void setName(std::string);
};

std::string Solid::getName(){
	return name;
}

void Solid::setName(std::string aName){
	name=aName;
}

int main(){
	Solid solid;
	solid.setName("solid0");
	std::cerr << solid.getName() << std::endl;
	return 0;
}
