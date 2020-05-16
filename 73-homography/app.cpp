#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

using namespace std;
using namespace cv;
int main(int argc, char** argv) {
	//-- Localize the object
	std::vector<Point2f> srcPoints;
	std::vector<Point2f> dstPoints;

// image points
	srcPoints.push_back(Point2f( 29.,  36.));
	srcPoints.push_back(Point2f(744.,  33.));
	srcPoints.push_back(Point2f( 29., 545.));
	srcPoints.push_back(Point2f(793., 490.));

// src points are measured in cm
	dstPoints.push_back(Point2f(  0., 100.));
	dstPoints.push_back(Point2f(600.,   0.));
	dstPoints.push_back(Point2f(200., 700.));
	dstPoints.push_back(Point2f(600., 600.));

	// Fill-in:
	// Push all other points A, B, C,...,Z
	// Fill-in: use the OpenCV findHomography to compute the homography matrix H.
	// Take the third parameter as just 0, which means use regular method using all points.
	Mat H=findHomography(srcPoints, dstPoints, 0);
//.	cout << "The computed homography matrix size is: " << endl;
//	cout << "rows: "<< H.rows << ", cols: "<< H.cols << endl;
//	for(int i=0;i<H.rows; ++i){for(int j=0; j<H.cols;++j){cout<<H.at<float>(i,j)<<",\t";}cout<<endl;}
	Mat Img=imread(argv[1],1);
	Mat Out_Img;
	// Fill-in:
	// Use the warpPerspective method of OpenCV to convert the input image Img to
	// the corrected image Out_Img of size 300x300 using H.
	warpPerspective(Img, Out_Img, H, Size(600, 700));
	imshow("Input", Img);
	imshow("Output", Out_Img);
	imwrite("output.png", Out_Img);

	cv::FileStorage fs("output.yaml", cv::FileStorage::WRITE);
     	fs << "homography_matrix" << H;
	fs.release();

	waitKey(0);
}
