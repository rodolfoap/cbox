#include <exception>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::VideoCapture cap;
int main(int argc, char** argv) {
	cv::Mat image1, frame;
	cap.open("PETS09-S2L1.mp4");
	cv::VideoWriter out=cv::VideoWriter("appsrc!queue!videoconvert!decodebin!x264enc!rtph264pay!udpsink host=192.168.1.159 port=5000", cv::CAP_GSTREAMER, 0, 30, cv::Size(768, 576));
	//cv::VideoWriter out=cv::VideoWriter("appsrc!queue!videoconvert!video/x-raw-yuv!rtpmp4vpay!udpsink host=127.0.0.1 port=5004", cv::CAP_GSTREAMER, 0, 30, cv::Size(768, 576));
	//cv::VideoWriter out=cv::VideoWriter("appsrc!queue!videoconvert!rtpmp4vpay send-config=true!udpsink host=127.0.0.1 port=5000", cv::CAP_GSTREAMER, 0, 30, cv::Size(768, 576));
	cap>>frame;
	while(!frame.empty()) {
		try {
			out.write(frame);
			imshow("frame", frame);
			cap>>frame;
		} catch(std::exception& e) {
			std::cerr<<"error:"<<e.what()<<std::endl;
		}
		cv::waitKey(1);
	}
	return 0;
}
