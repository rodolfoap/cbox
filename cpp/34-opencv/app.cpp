#include<iostream>
#include<opencv2/opencv.hpp> // Requires: apt install libopencv-dev python3-opencv

int main(){
	cv::Mat image;
	image=cv::imread("lena.jpg", 1);
	if(!image.data) return -1;

	cv::namedWindow("Lena", cv::WINDOW_AUTOSIZE);
	cv::imshow("Lena", image);
	cv::waitKey(0);
	return 0;
}
