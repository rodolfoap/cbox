#include<iostream>
#include<sstream>
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
	std::cerr << "intg=" << intg << std::endl;
	std::cerr << "flot=" << flot << std::endl;

	return 0;
}
