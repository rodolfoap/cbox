#include <stdio.h>
#include <tensorflow/c/c_api.h>
#include <iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

// Requires https://www.tensorflow.org/install/lang_c

int main(){
	//std::cerr<<"Hello, World!"<<std::endl;
  	printf("Hello from TensorFlow C library version %s\n", TF_Version());
	return 0;
}
