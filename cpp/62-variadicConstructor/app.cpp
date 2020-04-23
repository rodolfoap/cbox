#include <iostream>
#include <initializer_list>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

struct Polygon {
	Polygon(std::initializer_list<int> args){
		for (int i: args) std::cout << i << '\n';
	}
};

int main() {
	Polygon p({2, 3, 4, 5});
	std::cerr<<"Hello, World!"<<std::endl;
}
