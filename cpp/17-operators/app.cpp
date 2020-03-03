#include<iostream>

class Vector{
public:
	float mag, dir;
	Vector(float m, float d):mag(m), dir(d){}
	// Comparison 1
	bool operator!=(const Vector& other)		const{ return !(mag==other.mag && dir==other.dir); }
	// Comparison 2
	std::string operator==(const Vector& other)	const{
		if(mag==other.mag && dir==other.dir)
			return "MATCH";
		else
			return "NOMATCH";
	}
	// Addition
	Vector operator+(const Vector& other)		const{ return Vector(mag+other.mag, dir+other.dir); }
	// Addition method using the operator
	Vector add(const Vector& other)			const{ return *this + other; }
};
// Overload <<
std::ostream& operator<<(std::ostream& stream, const Vector& v){
	stream << "[" << v.mag << ":" << v.dir << "]";
	return stream;
}

int main(){
	Vector a(7, 9), b(4, 4);
	Vector c=a+b;
	Vector d=b.add(a);

	// operator== returns a std::string
	std::cerr << c << ", " << d << ": " << (c==d) << std::endl;

	// operator!= returns a bool
	std::cerr << a << ", " << b << ": " << ((a!=b)?"NE":"EQ") << std::endl;

	return 0;
}
