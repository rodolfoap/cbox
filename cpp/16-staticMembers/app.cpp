#include <iostream>

class Thing{
protected:
	static std::string name;
public:
	static std::string getName();
	static void setName(std::string);
};

// This is the key to static variable strings: it creates the member: std::string Thing::name; static members are declared INSIDE and defined OUTSIDE the class.
std::string Thing::name;

std::string Thing::getName(){
	return name;
}

void Thing::setName(std::string aName){
	name=aName;
}

int main(){
	Thing::setName("thing0");
	std::cerr << Thing::getName() << std::endl;
	return 0;
}
