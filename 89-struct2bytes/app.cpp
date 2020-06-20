#include <iostream>
#include <cstring>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

struct Register {
	char type;
	uint64_t hsize=sizeof(char)+sizeof(uint64_t);
	uint64_t dsize;
	char* data;
	Register(char t, uint64_t length, char* d): type(t), dsize(hsize+length), data(new char[dsize]) {
		sprintf(data, "%c%08d", type, dsize);
		memcpy(hsize+data, d, dsize);
	}

	//Register(uint64_t length, char* d): type(d), dsize(length), data(new char[length-hsize)
	//{memcpy(hsize+data, d, dsize);}

	~Register() { delete data; }
	void print(){
		log("Register: ("<<type<<", "<<dsize<<", "<<data<<")");
	}
};

int main(int argc, char** argv) {
	Register source( {'A', strlen(argv[1]), argv[1]} );
	source.print();

	// To bytes
	char b[source.dsize+1];
	memcpy(b, source.data, source.dsize);
	b[source.dsize]=0;
	log(b);

//	// To Struct
//	Register target(b, source.dsize);
//	target.print();
//	memcpy(&target, b, sizeof(target));
//	log("Register: ("<<target.yaw<<", "<<target.pitch<<", "<<target.roll<<")");
}
