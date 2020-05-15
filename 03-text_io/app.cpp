#include<iostream>
#include<string>
#include<algorithm>

class TextHolder{
public:
	// Constructor with initializer list
	TextHolder(std::string aname) :name(aname){}

	std::string name;
	void reverse(){
		std::reverse(this->name.begin(), this->name.end());
	}
};

int main(){
	TextHolder th("rodolfo");
	std::cerr << th.name << std::endl;
	th.reverse();
	std::cerr << th.name << std::endl;
}
// #include<algorithm> has a std::reverse(text.begin(), text.end());
// streams usage: system flow always to the left: std::cin >> stringVariable; std::cerr << std::endl;
