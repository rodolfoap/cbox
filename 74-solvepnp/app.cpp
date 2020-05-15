#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
	// Intrinsics

	cv::Mat distCoeffs = cv::Mat::zeros(8, 1, CV_64F);
	// | k1  k2  p1  p2  k3  k4  k5  k6 |
	std::cout << "distCoeffs:\n" << distCoeffs << std::endl;

	cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
	cameraMatrix.at<double>(0, 0) = 400.;	// fx, in pixels
	cameraMatrix.at<double>(1, 1) = 400.;	// fy, in pixels
	cameraMatrix.at<double>(0, 2) = 400.;	// cx, in pixels
	cameraMatrix.at<double>(1, 2) = 300.;	// cy, in pixels
	// | fx  0  cx |
	// | 0  fy  cy |
	// | 0   0   1 |
	std::cout << "cameraMatrix:\n" << cameraMatrix << std::endl;

	std::vector<cv::Point2f> imagePoints;
	std::vector<cv::Point3f> objectPoints;

	// image points
	imagePoints.push_back(cv::Point2f( 29.,  36.));
	imagePoints.push_back(cv::Point2f(744.,  33.));
	imagePoints.push_back(cv::Point2f( 29., 545.));
	imagePoints.push_back(cv::Point2f(793., 490.));

	//object points are measured in cm
	objectPoints.push_back(cv::Point3f(   0., 100., 0.));
	objectPoints.push_back(cv::Point3f( 600.,   0., 0.));
	objectPoints.push_back(cv::Point3f( 200., 700., 0.));
	objectPoints.push_back(cv::Point3f( 600., 600., 0.));

	cv::Mat rvec(1,3,cv::DataType<double>::type);
	cv::Mat tvec(1,3,cv::DataType<double>::type);
	cv::Mat rotationMatrix(3,3,cv::DataType<double>::type);
	cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);
	cv::Rodrigues(rvec,rotationMatrix);

	cv::Mat uvPoint = (cv::Mat_<double>(3, 1) << 320, 253, 1); // u, v

	cv::Mat leftSideMat  = rotationMatrix.inv() * cameraMatrix.inv() * uvPoint;
	cv::Mat rightSideMat = rotationMatrix.inv() * tvec;

	double s = (2 + rightSideMat.at<double>(2,0))/leftSideMat.at<double>(2,0);
	//285 represents the height Zconst

	std::cout << "P = " << rotationMatrix.inv() * (s * cameraMatrix.inv() * uvPoint - tvec) << std::endl;

	cv::FileStorage fs("output.yaml", cv::FileStorage::WRITE);
     	fs << "rmatrix" << rotationMatrix;
     	fs << "cmatrix" << cameraMatrix;
	fs.release();
	return 0;
}
