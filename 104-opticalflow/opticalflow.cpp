// See https://learnopencv.com/optical-flow-in-opencv/
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/optflow.hpp>
#include <opencv2/highgui.hpp>
#include "opticalflow.hpp"

void OpticalFlow::initCapture() {
	std::string source="video/dublin_stpatricks.mp4";
	// std::string source="video/tokyo_shinjuku.mp4";
	// std::string source="video/chicago_cubs.mp4";
	capture=cv::VideoCapture(cv::samples::findFile(source));
	if(!capture.isOpened()) {
		std::cerr<<"Unable to open file!"<<std::endl;
	}
}
void OpticalFlow::start() {
	cv::Mat prev, next;
	get_frame(prev);
	while(true) {
		get_frame(next);
		if(next.empty()) break;
		cv::Mat flow(prev.size(), CV_32FC2);

		/* Algorithm selected among:
		- cv::calcOpticalFlowFarneback(): Gunnar Farneback Dense Optical Flow
		- cv::optflow::calcOpticalFlowSparseToDense(): Lucas-Kanade Dense Pyramid
		- cv::optflow::calcOpticalFlowDenseRLOF(): Robust Local Optical Flow */
		cv::calcOpticalFlowFarneback(prev, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);

		// visualization
		cv::Mat flow_parts[2];
		cv::split(flow, flow_parts);
		cv::Mat magnitude, angle, magn_norm;
		cartToPolar(flow_parts[0], flow_parts[1], magnitude, angle, true);
		normalize(magnitude, magn_norm, 0.0f, 1.0f, cv::NORM_MINMAX);
		angle*=((1.f / 360.f) * (180.f / 255.f));
		// build hsv image
		cv::Mat _hsv[3], hsv, hsv8, bgr;
		_hsv[0]=angle;
		_hsv[1]=cv::Mat::ones(angle.size(), CV_32F);
		_hsv[2]=magn_norm;
		merge(_hsv, 3, hsv);
		hsv.convertTo(hsv8, CV_8U, 255.0);
		cvtColor(hsv8, bgr, cv::COLOR_HSV2BGR);
		cv::imshow("flow", bgr);
		if(cv::waitKey(1)>='0') break;
		prev=next.clone();
		counter++;
	}
}

void OpticalFlow::get_frame(cv::Mat& target) {
	cv::Mat frame;
	capture>>frame;
	if(frame.empty()) {
		target=frame.clone();
		return;
	}

	// Resize
	cv::Mat resized_frame;
	cv::resize(frame, resized_frame, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);

	cv::imshow("frame", resized_frame);
	cvtColor(resized_frame, target, cv::COLOR_BGR2GRAY);
}
