#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

void byval(char c){
	c+=10;
	std::cerr<<"byval: "<<+c<<" ["<<c<<"]"<<std::endl;
}
void byref(char& c){
	c+=10;
	std::cerr<<"byref: "<<+c<<" ["<<c<<"]"<<std::endl;
}
void byptr(char* c){
	*c+=10;
	std::cerr<<"byptr: "<<+(*c)<<" ["<<*c<<"]"<<std::endl;
}
int main(){
	char c=65;

	// The problem with pointers is related to the syntax of the
	// declaration vs. the syntax of the usage. In the following example,
	// the usage of p1 and p2 are identic, although declarations differ:

	char *p1=&c;		// Syntax "... *p1= ...", same meaning
        *p1=66;
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byval(*p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byref(*p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byptr(p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	std::cerr<<std::endl;

        char *p2;
	p2=&c;			// Syntax " ... p2= ...", same meaning
	*p2=67;
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byval(*p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byref(*p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;
	byptr(p1);
	std::cerr<<"c: "<<+c<<" ["<<c<<"]"<<std::endl;

	return 0;
}
