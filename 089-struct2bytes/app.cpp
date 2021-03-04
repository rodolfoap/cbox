#include <iostream>
#include <fstream>
#include <cstring>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)
#define fwrite(file, data){std::ofstream f; f.open(file); f<<data; f.close();}

struct Register {
	char type;
	uint64_t size; //packet size, does not include type
	char* data=nullptr;

	// When created with this constructor, data contains the type
	// This is intended to generate a serialized packet
	Register(char t, uint64_t length, char* d): type(t), size(length), data(new char[length+1]) {
		data[0]=t;
		memcpy(data+1, d, length);
	}

	// When created with this constructor, data does not contain the type
	// This is intended to deserialize a packet
	Register(uint64_t length, char* d): type(d[0]), size(length-1), data(new char[size]) {
		memcpy(data, d+1, length);
	}
	~Register() { delete data; }
	void print() { log("Struct: ("<<type<<", "<<size<<", "<<data<<")"); }
};

int main(int argc, char** argv) {
	log("Creating register");
	Register source( {'A', strlen(argv[1]), argv[1]} );
	source.print();

	log("Struct to bytes");
	char b[source.size+1];
	memcpy(b, source.data, source.size+1);
	log("BYTES: "<<b<<"["<<sizeof(b)<<"]");

	log("Writing to file");
	fwrite("data.dat", b);

	log("Bytes to struct");
	Register target(sizeof(b), b);
	target.print();
}
