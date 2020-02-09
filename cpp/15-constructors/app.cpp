#include<iostream>

class Thing {
protected:
	std::string name;
public:
	// Example initialization list: will assign aname to name
	Thing(std::string aname) :name(aname) {}
	void setName(std::string name){this->name=name;}
	std::string getName() const{return this->name;}
};

int main(){
	// This is a normal use of the constructor
	Thing thing("thing0");
	// This was not defined, so the compiler generates a copy-constructor (see below)
	Thing thong(thing);
	std::cerr << thong.getName() << std::endl; // thing0

	thong.setName("thong1");
	std::cerr << thong.getName() << std::endl; // thong1
	std::cerr << thing.getName() << std::endl; // thing0

	Thing thang=thong;
	std::cerr << thang.getName() << std::endl; // thong1
	thang.setName("thang2");
	std::cerr << thang.getName() << std::endl; // thang2
	return 0;
}
// If not provided, the compiler generates a copy-constructor, used like this: // a) Thing obj2(obj1); b) Thing obj2=obj1; which copies obj1 to obj2 in both cases
