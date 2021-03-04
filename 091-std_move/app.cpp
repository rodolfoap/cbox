#include <iostream>
#define log(t) std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"(): "<<t<<std::endl

struct Number{
	int* n;
	Number(){ log("D-CTOR"); }
	Number(int x){log("P-CTOR"); n=new int; *n=x; }
	Number(const Number& other):n(other.n) { log("Copy CTOR"); }
	Number(Number&& other){
		log("Move CTOR");
		n=other.n;
		other.n=nullptr;
	}
	Number& operator=(const Number& rhs){
		n=rhs.n;
		log("Copy OPTOR");
		return *this;
	}
	~Number(){log("DTOR");}
	void print(){ if(n)log(*n); else log("NULL");}
};

int main(){
	// Calls the default ctor.
	int d=27;
	Number d_ctor;
	d_ctor.n=&d;
	d_ctor.print();     // 27

	log("----");

	// Calls the parameter ctor.
	Number p_ctor{19};
	p_ctor.print();     // 19

	log("----");

	// Calls the copy ctor.
	Number copy_ctor=d_ctor;
	copy_ctor.print();  // 27
	d_ctor.print();     // 27

	log("----");

	// Calls the move ctor.
	d_ctor.print();     // 27
	Number move_ctor1((Number&&)d_ctor);
	d_ctor.print();     // NULL
	move_ctor1.print(); // 27

	log("----");

	// Calls the move ctor.
	p_ctor.print();     // 19
	Number move_ctor2=std::move(p_ctor);
	p_ctor.print();     // NULL
	move_ctor2.print(); // 19

	log("----");

	int c=279;
	Number copy_optor;  // D-CTOR
	copy_optor.n=&c;
	copy_optor.print(); // 279
	copy_optor=move_ctor2;
	copy_optor.print(); // 19

	log("----");

	return 0;
}
