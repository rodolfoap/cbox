#include <iostream>
// Virtual functions are overriden in execution time
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
	Thing& thing_ref = b;		// the type of thing_ref is Thing&
	Thing& solid_ref = d;		// the type of solid_ref is Thing& as well
	thing_ref.f();			// prints "Thing"
	solid_ref.f();			// prints "Solid"

	// virtual function call through pointer
	Thing* thing_ptr = &b;		// the type of thing_ptr is Thing*
	Thing* solid_ptr = &d;		// the type of solid_ptr is Thing* as well
	thing_ptr->f();		// prints "Thing"
	solid_ptr->f();		// prints "Solid"

	// non-virtual function call
	thing_ref.Thing::f();		// prints "Thing"
	solid_ref.Thing::f();		// prints "Thing"
}
