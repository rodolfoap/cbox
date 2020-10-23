#include <iostream>

class Thing {
protected:
	std::string name;
};

class Solid: public Thing {
public:
	std::string getName() const;
	void setName(std::string);
};

std::string Solid::getName() const {
	return this->name;
}

void Solid::setName(std::string name) {
	this->name=name;
}

int main() {
	Solid solid;
	solid.setName("solid0");
	std::cerr<<solid.getName()<<std::endl;
	return 0;
}
