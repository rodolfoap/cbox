#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
typedef struct Register{
	uint id;
	char name[32];
	int zone;
	float score;
	char state[32];
	void print(){ printf("%d:%s:%d:%f:%s\n", id, name, zone, score, state); }
} Register;
int main() {
	std::ifstream detectionFile;
	std::string detLine;
	char ch;
	detectionFile.open("table.csv");
	if(!detectionFile.is_open()) return 1;
	std::vector<Register> regs;
	while(getline(detectionFile, detLine)) {
		std::istringstream ss;
		Register r;
		ss.str(detLine);
		ss >> r.id >> r.name >> r.zone >> r.score >> r.state;
		ss.str("");
		regs.push_back(r);
		r.print();
	}
	detectionFile.close();
	return 0;
}
