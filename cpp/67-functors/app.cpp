#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class Adder{
public:
	int total;
	Adder(int n): total(n) {
		std::cerr<<"Starting: total=="<<total<<std::endl;
	}
	void operator ()(int n){
		total+=n;
		std::cerr<<"total+="<<n<<"=="<<total<<std::endl;
	}
};

int main(){
	// Functors are smart functions, that can save their state.
	Adder adder(5);
	adder(2);
	adder(1);
	adder(5);
	//or just
	Adder(8)(5);
	return 0;
}
