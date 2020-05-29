#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

std::pair<double, double> slope(const std::vector<double>& x, const std::vector<double>& y) {
	const auto n   =x.size();
	const auto s_x =std::accumulate(x.begin(), x.end(), 0.0);
	const auto s_y =std::accumulate(y.begin(), y.end(), 0.0);
	const auto s_x2=std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
	const auto s_xy=std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
	const auto m   =(n*s_xy-s_x*s_y)/(n*s_x2-s_x*s_x);
	const auto b   =(s_y-m*s_x)/n;
	return std::pair<double, double>(m, b);
}

int main() {
	std::vector<double> x{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<double> y{2, 1, 4, 3, 5, 6, 7, 8};
	std::pair<double, double> mb=slope(x, y);
	std::cerr<<"y="<<mb.first<<"x+"<<mb.second<<std::endl;
	for(int i=0; i<x.size(); i++) std::cerr<<y[i]<<"="<<mb.first<<"*"<<x[i]<<"+"<<mb.second<<"; gives:"<<mb.first*x[i]+mb.second<<std::endl;
	return 0;
}
