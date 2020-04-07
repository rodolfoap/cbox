#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define PERIOD 5

int main(){
	uint p=0;
	for(int k=0; k<1000; k++){
		p=++p%PERIOD;
		std::cerr<<(p==0?'#':'.');
	}
	std::cerr<<std::endl;
	return 0;
}
