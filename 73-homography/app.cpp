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
	// Example: Point V
	dstPoints.push_back(Point2f(0, 0)); srcPoints.push_back(Point2f(69, 354));
	//a
	dstPoints.push_back(Point2f(50, 0)); srcPoints.push_back(Point2f(158, 360));
	//b
	dstPoints.push_back(Point2f(100, 0)); srcPoints.push_back(Point2f(247, 362));
	//c
	dstPoints.push_back(Point2f(150, 0)); srcPoints.push_back(Point2f(337, 373));
	//d
	dstPoints.push_back(Point2f(200, 0)); srcPoints.push_back(Point2f(425, 375));
	//e
	dstPoints.push_back(Point2f(250, 0)); srcPoints.push_back(Point2f(517, 383));
	//f
	dstPoints.push_back(Point2f(300, 0)); srcPoints.push_back(Point2f(610, 390));
	//g
	dstPoints.push_back(Point2f(300, 50)); srcPoints.push_back(Point2f(605, 319));
	//h
	dstPoints.push_back(Point2f(300, 100)); srcPoints.push_back(Point2f(600, 257));
	//i
	dstPoints.push_back(Point2f(300, 150)); srcPoints.push_back(Point2f(595, 202));
	//j
	dstPoints.push_back(Point2f(300, 200)); srcPoints.push_back(Point2f(594, 155));
	//k
	dstPoints.push_back(Point2f(300, 250)); srcPoints.push_back(Point2f(592, 114));
	//l
	dstPoints.push_back(Point2f(250, 250)); srcPoints.push_back(Point2f(522, 108));
	//m
	dstPoints.push_back(Point2f(200, 250)); srcPoints.push_back(Point2f(453, 108));
	//n
	dstPoints.push_back(Point2f(150, 250)); srcPoints.push_back(Point2f(386, 102));
	//o
	dstPoints.push_back(Point2f(100, 250)); srcPoints.push_back(Point2f(325, 100));
	//p
	dstPoints.push_back(Point2f(50, 250)); srcPoints.push_back(Point2f(257, 95));
	//q
	dstPoints.push_back(Point2f(0, 250)); srcPoints.push_back(Point2f(195, 93));
	//r
	dstPoints.push_back(Point2f(0, 200)); srcPoints.push_back(Point2f(170, 133));
	//s
	dstPoints.push_back(Point2f(0, 150)); srcPoints.push_back(Point2f(150, 175));
	//t
	dstPoints.push_back(Point2f(0, 100)); srcPoints.push_back(Point2f(130, 228));
	//u
	dstPoints.push_back(Point2f(0, 50)); srcPoints.push_back(Point2f(100, 285));
	//w
	dstPoints.push_back(Point2f(50, 50)); srcPoints.push_back(Point2f(180, 290));
	//x
	dstPoints.push_back(Point2f(250, 50)); srcPoints.push_back(Point2f(517, 312));
	//y
	dstPoints.push_back(Point2f(250, 200)); srcPoints.push_back(Point2f(522, 153));
	//z
	dstPoints.push_back(Point2f(50, 200)); srcPoints.push_back(Point2f(240, 137));
	// Fill-in:
	// Push all other points A, B, C,...,Z
	// Fill-in: use the OpenCV findHomography to compute the homography matrix H.
	// Take the third parameter as just 0, which means use regular method using all points.
	Mat H=findHomography(srcPoints,dstPoints,0);
	cout << "The computed homography matrix size is: " << endl;
	cout << "rows: "<< H.rows << ", cols: "<< H.cols << endl;
	for (int i = 0; i < H.rows; ++i) {
		for (int j = 0; j < H.cols; ++j) {
			cout << H.at<float>(i, j) << ",\t";
		}
		cout << endl;
	}
	Mat Img = imread(argv[1],1);
	Mat Out_Img;
	// Fill-in:
	// Use the warpPerspective method of OpenCV to convert the input image Img to
	// the corrected image Out_Img of size 300x300 using H.
	warpPerspective(Img,Out_Img,H,Size(300,300));
	imshow("Input", Img);
	imshow("Output", Out_Img);
	imwrite("output.png", Out_Img);

	cv::FileStorage fs("output.yaml", cv::FileStorage::WRITE);
     	fs << "homography_matrix" << H;
	fs.release();

	waitKey(0);
}
