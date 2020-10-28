#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//using namespace cv;

cv::VideoCapture cap;
int main(int argc, char **argv) {
	cv::Mat image1, frame;
	cap.open("PETS09-S2L1.mp4");
	cv::VideoWriter out=cv::VideoWriter("appsrc ! queue ! videoconvert ! video/x-raw, format=I420, width=768, height=576, framerate=30/1 ! rtpvrawpay ! udpsink host=127.0.0.1 port=5004", 
			cv::CAP_GSTREAMER, 0, 30, cv::Size(768, 576));
	while(1) {
		cap>>frame;
		if(frame.empty()) break;
		out.write(frame);
		imshow("frame", frame);
		cv::waitKey(30);
	}
	return 0;
}
