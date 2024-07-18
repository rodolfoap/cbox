#include <iostream>
#include <opencv2/opencv.hpp> // Requires: apt install libopencv-dev python3-opencv

int main() {
	cv::VideoCapture cap;
	if(!cap.open("video/dublin_stpatricks.mp4")) {
		std::cerr<<"Error opening video."<<std::endl;
		return -1;
	}
	cv::Mat frame;
	cap>>frame;
	while(frame.data) {
		cv::namedWindow("Lena", cv::WINDOW_AUTOSIZE);
		cv::imshow("Lena", frame);
		if(cv::waitKey(33)>='0') break; // 30 FPS -> wait 33.333...ms
		cap>>frame;
	}

	cap.release();
	return 0;

}
