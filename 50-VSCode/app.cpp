#include <iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

int main() {
	std::cerr<<"Hello, World!"<<std::endl;
	return 0;
}
