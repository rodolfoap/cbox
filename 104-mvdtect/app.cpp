#include <iostream>
#include <opencv2/opencv.hpp> // Requires: apt install libopencv-dev python3-opencv
#include <opencv2/optflow.hpp>

int main() {
	cv::VideoCapture cap;
	if(!cap.open("video/dublin_stpatricks.mp4")) {
		std::cerr<<"Error opening video."<<std::endl;
		return -1;
	}
	cv::namedWindow("flow", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("video", cv::WINDOW_AUTOSIZE);
	cv::Mat frame, frame_old, frame_new, flow;
	cap>>frame;
	resize(frame, frame_old, cv::Size(300, 200), cv::INTER_LINEAR);
	frame_new=cv::Mat(frame_old);
	while(frame_new.data) {
		std::cerr<<".";
		cv::optflow::calcOpticalFlowSF(frame_old, frame_new, flow, 3, 2, 4);

		cv::Mat xy[2];
		cv::split(flow, xy);
		//calculate angle and magnitude
		cv::Mat magnitude, angle;
		cv::cartToPolar(xy[0], xy[1], magnitude, angle, true);
		//translate magnitude to range [0;1]
		double mag_max;
		cv::minMaxLoc(magnitude, 0, &mag_max);
		magnitude.convertTo(magnitude, -1, 1.0/mag_max);

		//build hsv image
		cv::Mat _hsv[3], hsv;
		_hsv[0] = angle;
		_hsv[1] = cv::Mat::ones(angle.size(), CV_32F);
		_hsv[2] = magnitude;
		cv::merge(_hsv, 3, hsv);

		//convert to BGR and show
		cv::Mat bgr;//CV_32FC3 matrix
		cvtColor(hsv, bgr, cv::COLOR_HSV2BGR);
		cv::imshow("flow", bgr);
		cv::imshow("video", frame_new);

		if(cv::waitKey(1)>='0') break; // 30 FPS -> wait 33.333...ms
		frame_old=cv::Mat(frame_new);
		cap>>frame;
		resize(frame, frame_new, cv::Size(300, 200), cv::INTER_LINEAR);
	}
	cap.release();
	return 0;
}
