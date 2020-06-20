#include <iostream>
#include <fstream>
#include <cstring>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

struct Register {
	char type;
	uint64_t hsize=sizeof(char)+sizeof(uint64_t);
	uint64_t dsize;
	char* payload;
	char* packet;

	Register(char t, uint64_t length, char* d): type(t), dsize(hsize+length),
		payload(new char[length]), packet(new char[dsize]) {

		sprintf(packet, "%c%08d", type, dsize);
		memcpy(packet+hsize, d, length);
		memcpy(payload, d, length);
	}

	Register(uint64_t length, char* d): type(d[0]), dsize(length), payload(new char[length-hsize]) {
		memcpy(payload, d+hsize, dsize);
	}

	~Register() { delete payload; }
	void print() {
		log("Register: ("<<type<<", "<<dsize<<", "<<payload<<", "<<packet<<")");
	}
};

int main(int argc, char** argv) {
	Register source( {'A', strlen(argv[1]), argv[1]} );
	source.print();

	// To bytes
	char b[source.dsize+1];
	memcpy(b, source.packet, source.dsize);
	b[source.dsize]=0;
	log(b);
	log(sizeof(b));

	std::ofstream("data.dat");
	// To Struct
//	Register target(sizeof(b), b);
//	target.print();
//	memcpy(&target, b, sizeof(target));
//	log("Register: ("<<target.yaw<<", "<<target.pitch<<", "<<target.roll<<")");
}
