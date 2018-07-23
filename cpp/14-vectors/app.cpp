#include <iostream>
#include <vector>

class Thing {
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
	Solid solid0, solid1, solid2;
	solid0.setName("solid0");
	solid1.setName("solid1");
	solid2.setName("solid2");

	std::vector<Solid> vSolid(4);
	vSolid[0]=solid0;
	vSolid[1]=solid1;
	vSolid[2]=solid2;

	std::cerr << vSolid[2].getName() << std::endl;
	std::cerr << vSolid[1].getName() << std::endl;
	std::cerr << vSolid[0].getName() << std::endl;

	return 0;
}
