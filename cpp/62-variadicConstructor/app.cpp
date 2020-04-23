#include <iostream>
#include <initializer_list>
#include <utility>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

struct Polygon {
	Polygon(std::initializer_list<std::pair<int, int>> args){
		for(std::pair<int, int> pair: args) std::cerr<<'['<<std::get<0>(pair)<<','<<std::get<1>(pair)<<']'<<'\n';
	}
};

int main() {
	Polygon p({{2, 3}, {4, 5}});
}
