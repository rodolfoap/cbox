#include<iostream>
#include<string>
#include<algorithm>

class TextHolder{
public:
	std::string name;
};

int main(){
	TextHolder th;
	std::cin  >> th.name;
	std::reverse(th.name.begin(), th.name.end());
	std::cerr << th.name << std::endl;
}
// #include<algorithm> has a std::reverse(text.begin(), text.end());
// streams usage: system flow always to the left: std::cin >> stringVariable; std::cerr << std::endl;
