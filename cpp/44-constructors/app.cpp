#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#include <cstring>

class String{
public:
	char* buffer;
	int size;
	String(const char* value){
		this->size=strlen(value);
		buffer=new char[this->size+1];
		memcpy(this->buffer, value, this->size);
		buffer[this->size]=0;
	}
	// Destructor
	~String(){
		// Without a copy constructor, destroying two objects will
		// cause a double delete, since both *buffers point to the
		// same address
		delete[] buffer;
	}

	// Copy constructor, what the system provides:
	// String(const String& other): buffer(other.buffer), size(other.size) {}
	// Notice that the same addresses are pointed to!

	// Copy constructor, simplest option:
	// String(const String& other)=delete;

	// Copy constructor
	String(const String& other): size(other.size) {
		buffer=new char[size+1];
		memcpy(buffer, other.buffer, this->size+1);
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};
std::ostream& operator<<(std::ostream& stream, const String& string){
	stream << string.buffer;
	return stream;
}

int main(){
	{
	String s="john";
	std::cerr<<"buffer: "<<s<<std::endl;

	// Without a copy constructor, the *buffer pointer on the new object
	// will point to the same address. That is called "shallow copy"
	// (superficial copy). There is where we need a copy constructor.
	String p=s;
LOG
	}
LOG
	return 0;
}
