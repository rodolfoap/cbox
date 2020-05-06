#include <iostream>
#include <sstream>
#include <fstream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(){
	std::ostringstream oss;
	oss << "N[" << 2 << .5;
	oss << "]";
	// Output: N[20.5]
	std::cerr << oss.str() << std::endl;

	int intg; float flot;
	std::istringstream iss;
	iss.str("2 3.2");
	iss >> intg;
	iss >> flot;
	// Output: intg=2
	std::cerr << "intg=" << intg << std::endl;
	// Output: flot=3.2
	std::cerr << "flot=" << flot << std::endl;

	return 0;
}

