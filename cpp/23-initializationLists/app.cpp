#include<iostream>

class Thing{
private:
	const std::string name;
public:
	Thing(std::string aName) :name(aName) {}
	std::string getName(){
		return this->name;
	}
};

int main(){
	Thing thing("thing0");
	std::cerr << thing.getName() << std::endl;
	return 0;
}
// The initialization list "Thing(std::string aName) :name(aName){}" defines the default value for a constant.
