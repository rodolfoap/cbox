#include<iostream>

class Vector{
public:
	float mag, dir;
	Vector(float m, float d):mag(m), dir(d){}
	// Comparison
	bool operator==(const Vector& other)	const{ return (mag==other.mag && dir==other.dir); }
	// Addition
	Vector operator+(const Vector& other)	const{ return Vector(mag+other.mag, dir+other.dir); }
	// Addition method using the operator
	Vector add(const Vector& other)		const{ return *this + other; }
};
// Overload <<
std::ostream& operator<<(std::ostream& stream, const Vector& v){
	stream << "[" << v.mag << ":" << v.dir << "]";
	return stream;
}

int main(){
	Vector a(7, 9);
	Vector b(4, 4);
	Vector c=a+b;
	Vector d=b.add(a);
	std::cerr << a << std::endl;
	std::cerr << b << std::endl;
	std::cerr << c << std::endl;
	std::cerr << d << std::endl;
	std::cerr << "C and D are " <<((c==d)?"equal":"different") << std::endl;
	std::cerr << "A and D are " <<((a==d)?"equal":"different") << std::endl;
	return 0;
}
