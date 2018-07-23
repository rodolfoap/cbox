#include <iostream>
struct Thing {
	virtual void f() { std::cerr << "Thing" << std::endl; }
};
struct Solid :Thing {
	void f() override { std::cerr << "Solid" << std::endl; }
};
int main() {
	Thing b;
	Solid d;

	// virtual function call through reference
	Thing& br = b;		// the type of br is Thing&
	Thing& dr = d;		// the type of dr is Thing& as well
	br.f();			// prints "Thing"
	dr.f();			// prints "Solid"

	// virtual function call through pointer
	Thing* bp = &b;		// the type of bp is Thing*
	Thing* dp = &d;		// the type of dp is Thing* as well
	bp->f();		// prints "Thing"
	dp->f();		// prints "Solid"

	// non-virtual function call
	br.Thing::f();		// prints "Thing"
	dr.Thing::f();		// prints "Thing"
}
