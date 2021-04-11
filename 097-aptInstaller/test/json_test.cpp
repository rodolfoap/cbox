#include <nlohmann/json.hpp>
#include <iostream>

int main(){
	nlohmann::json j;
	j["Hello"]="World";
	std::cerr<<j.dump()<<std::endl;
	return 0;
}
