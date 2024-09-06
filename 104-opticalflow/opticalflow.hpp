#ifndef OPTICALFLOW_H
#define OPTICALFLOW_H

#include <opencv2/opencv.hpp>

class OpticalFlow {
public:
	void initCapture();
	void start();

private:
	int counter;
	cv::VideoCapture capture;
	void get_frame(cv::Mat& target);
};

#endif // OPTICALFLOW_H
