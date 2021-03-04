#include<iostream>
#define log(text)(std::cerr<<text<<std::endl)

class Entity{
private:
	int n;
public:
	Entity(int n):n(n){}
	void print() {log(n);}
	// Declared as friend
	friend void modify(Entity&);
};

void modify(Entity& e){
	// Accessing the private member
	e.n=e.n*21;
}

int main(){
	Entity e(19);
	e.print();

	modify(e);
	e.print();

	return 0;
}
