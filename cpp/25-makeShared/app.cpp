#include <iostream>
#include <memory>
#define LOG fprintf(stderr, ">>> %s:%d:%s \n", __FILE__, __LINE__, __func__);

struct Snitch {
	std::string name;
	Snitch() {
		std::cout << "Constructor[" << name << "]" << std::endl;
	}
	Snitch(std::string aName) {
		name=aName;
		std::cout << "Constructor[" << name << "]" << std::endl;
	}
	~Snitch() {
		std::cout << "Destructor[" << name << "]" << std::endl;
	}
	Snitch(Snitch const&) {
		std::cout << "Copy Constructor[" << name << "]" << std::endl;
	}
	Snitch(Snitch&&) {
		std::cout << "Move Constructor[" << name << "]" << std::endl;
	}
	void setName(std::string aName){
		name=aName;
	}
};

int main() {
LOG
	// This is a stack variable
	Snitch s1("s1");
LOG
	// Another stack variable, copying the first one
	Snitch s2=s1;
	s2.setName("s2");
LOG
	{ // SCOPE of pointers existence START
		Snitch s3=s1;
		s3.setName("s3");
LOG
		Snitch s4=std::move(s3);
		s4.setName("s4");
	} // SCOPE of pointers existence END
LOG
	auto snitch = std::make_shared<Snitch>("Snitch");
LOG
	auto another_snitch = snitch;
LOG
	std::cerr << "Equal: " << (snitch == another_snitch) << std::endl;
LOG
	{ 	auto scoped_snitch = snitch;
LOG
		auto scoped_another_snitch = scoped_snitch; }
LOG
}
