#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
std::vector<std::vector<bool>> grid;
std::vector<std::vector<int>> igrid;

int getNeigh(int y, int x, int h, int w) {
	if(x>=0 && y>=0 && x<w && y<h) return grid[y][x]?1:0; else return 0;
}

int main() {
	// Read binary file
	std::ifstream infile("binary.array");
	std::string line;
	int value;
	while(std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<bool> temp;
		while(iss>>value) temp.push_back(value==1?true:false);
		grid.push_back(temp);
	}
	int height=grid.size();
	int width=grid[0].size();
	while(true) {
		std::cout<<"\033[2J\033[1;1H"; // cls
		igrid=std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
		for(int y=0; y<height; y++) {
			for(int x=0; x<width; x++) {
				// Calc neighbors matrix
				igrid[y][x]+=getNeigh(y-1, x-1, height, width);
				igrid[y][x]+=getNeigh(y-1, x  , height, width);
				igrid[y][x]+=getNeigh(y-1, x+1, height, width);
				igrid[y][x]+=getNeigh(y  , x-1, height, width);
				igrid[y][x]+=getNeigh(y  , x+1, height, width);
				igrid[y][x]+=getNeigh(y+1, x-1, height, width);
				igrid[y][x]+=getNeigh(y+1, x  , height, width);
				igrid[y][x]+=getNeigh(y+1, x+1, height, width);
				// Draw life matrix
				std::cerr<<(grid[y][x]?std::to_string(igrid[y][x]):".")<<' ';
			}
			std::cerr<<std::endl;
		}
		std::cerr<<std::endl;

		for(int y=0; y<height; y++) {
			for(int x=0; x<width; x++) {
				// Apply life rules
				switch(igrid[y][x]) {
					case 3: grid[y][x]=true; break;
					case 2: break;
					default: grid[y][x]=false;
				}
				// And draw neighbors matrix
				// std::cerr<<igrid[y][x]<<" ";
			}
			// std::cerr<<std::endl;
		}
		usleep(200000);
		// Or use this to debug:
		// std::cin.ignore();
	}
	return 0;
}

