#include <stdio.h>
#include <bits/stdc++.h>

#define LOG fprintf(stderr, ">>> %s:%d:%s \n", __FILE__, __LINE__, __func__);

using namespace std;
class Greeter {
	// Access specifier
	public:

	// Data Members
	string target;
	int id;

	// Constructors
	Greeter() { LOG }
	Greeter(int x) { LOG id=x; }
	~Greeter() { LOG }

	// Member Functions()
	void getId();
	void doGoodbye();
	void doHello() { LOG cout << "Hello, " << target << "!\n"; }
};

void Greeter::doGoodbye() { LOG cout << "Goodbye, " << target << "!\n"; }
void Greeter::getId() { LOG cout << "ID=" << id << "\n"; }

int main() {
	LOG
	Greeter obj1;
	obj1.target = "World";
	obj1.doHello();

	{
		Greeter obj2;
	}

	Greeter obj3(13);
	obj3.getId();

	return 0;
}
