#include <iostream>

class Thing{
protected:
	std::string name;
};

class Solid :public Thing{
public:
	std::string getName() const;
	void setName(std::string);
};

std::string Solid::getName() const{
	return this->name;
}

void Solid::setName(std::string name){
	this->name=name;
}

int main(){
	Solid solid;
	solid.setName("solid0");
	std::cerr << solid.getName() << std::endl;
	return 0;
}

// A CONST function  [std::string getName() const;] implies that no members can be modified. Getters should be CONST.
// The arrow is used instead a dot. We need *foo.bar, but the dot is evaluated first, so we should use (*foo).bar, which is the same as foo->bar.
