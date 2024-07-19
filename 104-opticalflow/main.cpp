// See https://learnopencv.com/optical-flow-in-opencv/
#include "opticalflow.cpp"

int main() {
	OpticalFlow of;
	of.initCapture();
	of.start();
	return 0;
}
