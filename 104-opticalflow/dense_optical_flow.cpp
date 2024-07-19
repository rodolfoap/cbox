#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

template <typename Method, typename... Args>
void dense_optical_flow(std::string filename, bool save, Method method, bool to_gray, Args&&... args){
    cv::VideoCapture capture(cv::samples::findFile(filename));
    if (!capture.isOpened()) {
        std::cerr << "Unable to open file!" << std::endl;
    }
    cv::Mat frame1, prvs;
    capture >> frame1;
    if (to_gray)
        cvtColor(frame1, prvs, cv::COLOR_BGR2GRAY);
    else
        prvs = frame1;
    int counter = 0;
    while (true) {
        cv::Mat frame2, next;
        capture >> frame2;
        if (frame2.empty())
            break;
        if (to_gray)
            cvtColor(frame2, next, cv::COLOR_BGR2GRAY);
        else
            next = frame2;
        cv::Mat flow(prvs.size(), CV_32FC2);
        method(prvs, next, flow, std::forward<Args>(args)...);
        // visualization
        cv::Mat flow_parts[2];
        cv::split(flow, flow_parts);
        cv::Mat magnitude, angle, magn_norm;
        cartToPolar(flow_parts[0], flow_parts[1], magnitude, angle, true);
        normalize(magnitude, magn_norm, 0.0f, 1.0f, cv::NORM_MINMAX);
        angle *= ((1.f / 360.f) * (180.f / 255.f));
        //build hsv image
        cv::Mat _hsv[3], hsv, hsv8, bgr;
        _hsv[0] = angle;
        _hsv[1] = cv::Mat::ones(angle.size(), CV_32F);
        _hsv[2] = magn_norm;
        merge(_hsv, 3, hsv);
        hsv.convertTo(hsv8, CV_8U, 255.0);
        cvtColor(hsv8, bgr, cv::COLOR_HSV2BGR);
        if (save) {
            std::string save_path = "./optical_flow_frames/frame_" + std::to_string(counter) + ".jpg";
            imwrite(save_path, bgr);
        }
        imshow("frame", frame2);
        imshow("flow", bgr);
        if(cv::waitKey(1)>='0') break; // 30 FPS -> wait 33.333...ms
        prvs = next;
        counter++;
    }
}

