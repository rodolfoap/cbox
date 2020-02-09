#include <iostream>

class Thing{
protected:
	static std::string name;
public:
	static std::string getName() { return name; }
	static void setName(std::string aname){ name=aname; }
};

// This is the key to static variable strings: it creates the member std::string name;
// static members are declared INSIDE and defined OUTSIDE the class.
std::string Thing::name;

int main(){
	Thing::setName("thing0");
	std::cerr << Thing::getName() << std::endl;
	return 0;
}
