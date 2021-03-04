#include <iostream>
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#define LOG std::cerr<<">>>"<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text) (std::cerr<<text<<std::endl)

int main(int argc, char** argv) {
	Poco::MD5Engine md5;
	Poco::DigestOutputStream ostream(md5);
	ostream<<"abcdefghijklmnopqrstuvwxyz";
	ostream.close();
	std::cout<<Poco::DigestEngine::digestToHex(md5.digest())<<std::endl;
	return 0;
}
