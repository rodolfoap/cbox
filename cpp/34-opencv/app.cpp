#include<iostream>
#include<opencv2/opencv.hpp> // Requires: apt install libopencv-dev python3-opencv

int main(){
	cv::Mat image;
	image=cv::imread("lena.jpg", 1);
	if(!image.data){
		std::cerr<<"No image data."<<std::endl;
		return -1;
	}
	cv::namedWindow("Girl", cv::WINDOW_AUTOSIZE);
	cv::imshow("Girl", image);
	cv::waitKey(0);
	return 0;
}
