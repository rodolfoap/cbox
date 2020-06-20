#include <iostream>
#include <fstream>
#include <cstring>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)
#define fwrite(file, data){std::ofstream f; f.open(file); f<<data; f.close();}

struct Register {
	char type;
	uint64_t hsize=sizeof(char)+sizeof(uint64_t);
	uint64_t dsize;
	char* packet;

	// When using this constructor,  data=[TYPE+DSIZE+DATA]
	Register(char t, uint64_t length, char* d): type(t), dsize(hsize+length), packet(new char[dsize]) {
		sprintf(packet, "%c%08d", type, dsize);
		memcpy(packet+hsize, d, length);
	}

	// When using this constructor, type=DATA[0], dsize=DATA[1..8], data=DATA, 
	Register(uint64_t length, char* d): type(d[0]), dsize(length), packet(new char[length-hsize]) {
		memcpy(packet, d+hsize, dsize);
	}

	~Register() { delete packet; }
	void print() {
		log("Register: ("<<type<<", "<<dsize<<", "<<packet<<")");
	}
};

int main(int argc, char** argv) {
	Register source( {'A', strlen(argv[1]), argv[1]} );
	source.print();

	// To bytes
	char b[source.dsize];
	memcpy(b, source.packet, source.dsize);
	log(b);
	log(sizeof(b));

	fwrite("data.dat", b);

	// To Struct
//	Register target(sizeof(b), b);
//	target.print();
//	memcpy(&target, b, sizeof(target));
//	log("Register: ("<<target.yaw<<", "<<target.pitch<<", "<<target.roll<<")");
}
