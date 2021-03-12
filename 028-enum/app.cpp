#include<iostream>
#define log(text)(std::cerr<<text<<std::endl)

int main(){
	// int Moe=0, Curly=1, Larry=2;
	enum Stooge {Moe, Curly, Larry};

	Stooge s=Larry;
	if(s==Larry) log("Stooge: "<<Larry);

	return 0;
}
