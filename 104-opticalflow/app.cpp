#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/optflow.hpp>
#include "dense_optical_flow.cpp"
//#include <sys/stat.h>

int main(int argc, char** argv) {
	std::string source="video/dublin_stpatricks.mp4";
	bool save=false;
	bool to_gray=true;

	/*** Farneback ***/
	dense_optical_flow(source, save, cv::calcOpticalFlowFarneback, to_gray, 0.5, 3, 15, 3, 5, 1.2, 0);

    /*** Lucas-Kanade Dense Pyramid ***/
    // dense_optical_flow(source, save, cv::optflow::calcOpticalFlowSparseToDense, to_gray, 8, 128, 0.05f, true, 500.0f, 1.5f);

    /*** RLOF ***/
    // to_gray=false;
    // dense_optical_flow(
    //     source, save, cv::optflow::calcOpticalFlowDenseRLOF, to_gray,
    //     Ptr<cv::optflow::RLOFOpticalFlowParameter>(), 1.f, Size(6, 6),
    //     cv::optflow::InterpolationType::INTERP_EPIC, 128, 0.05f, 999.0f, 15, 100, true, 500.0f, 1.5f, false
    // );
	return 0;
}