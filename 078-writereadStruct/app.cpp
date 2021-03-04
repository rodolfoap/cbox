#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#define LOG std::cerr<<">>>"<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text) (std::cerr<<text<<std::endl)
typedef struct Register {
	uint id;
	std::string name;
	int zone;
	float score;
	std::string state;
	void print() { printf("%d:%s:%d:%f:%s\n", id, name.c_str(), zone, score, state.c_str()); }
	Register() {}
	Register(uint i, std::string n, int z, float s, std::string t):id(i), name(n), zone(z), score(s), state(t) {}
} Register;
void save() {
	log("Saving...");
	Register regs[4]{{1927, "Frank_Holdsworth", 62, 0.32728, "Arizona"},
		{1862, "Jim_Scofield", 32, 0.13237, "Arkansas"},
		{6271, "Thelonious_Grenadier", 44, 0.42864, "Missouri"},
		{8261, "Albert_Swallow", 51, 0.28674, "Toronto"}};
	std::ofstream outFile;
	outFile.open("table.data");
	char s=' ';
	for(int i=0; i<4; ++i) {
		std::cerr<<regs[i].id<<s<<regs[i].name<<s<<regs[i].zone<<s<<regs[i].score<<s<<regs[i].state<<std::endl;
		outFile<<regs[i].id<<s<<regs[i].name<<s<<regs[i].zone<<s<<regs[i].score<<s<<regs[i].state<<std::endl;
	}
	outFile.close();
	log("Done.");
}
void load() {
	log("Loading...");
	std::ifstream inFile;
	inFile.open("table.data");
	if(!inFile.is_open()) exit(1);
	std::string line;
	while(getline(inFile, line)) {
		Register r;
		std::istringstream ss(line);
		ss>>r.id>>r.name>>r.zone>>r.score>>r.state;
		ss.str("");
		r.print();
	}
	inFile.close();
	log("Done.");
}
int main() {
	save();
	load();
	return 0;
}
