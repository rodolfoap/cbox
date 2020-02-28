#include <stdio.h>

// Requires: apt install libopencv-dev python3-opencv
#include <opencv2/opencv.hpp>

//using namespace cv;
int main(){
	cv::Mat image;
	image = cv::imread("girl.jpg", 1 );
	if ( !image.data ) {
		printf("No image data \n");
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);
	waitKey(0);
	return 0;
}
