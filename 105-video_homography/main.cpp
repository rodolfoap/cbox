#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the video file
    cv::VideoCapture cap("video/ratp.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video file." << std::endl;
        return -1;
    }

    // Get video properties
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);

    // Define the codec and create VideoWriter object
    cv::VideoWriter out("trapezoid.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), fps, cv::Size(frame_width, frame_height));

    // Define source points (corners of the original frame)
    std::vector<cv::Point2f> src_points = { {0, 0}, {static_cast<float>(frame_width), 0}, {static_cast<float>(frame_width), static_cast<float>(frame_height)}, {0, static_cast<float>(frame_height)} };

    // Define destination points (corners of the trapezoid)
    std::vector<cv::Point2f> dst_points = { {-7600, -8000}, {8200, -8000}, {320, 576}, {280, 576} };

    // Calculate the homography matrix
    cv::Mat H = cv::findHomography(src_points, dst_points);

    cv::Mat frame, warped_frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        // Apply the homography transformation
        cv::warpPerspective(frame, warped_frame, H, cv::Size(frame_width, frame_height));

        // Write the frame to the output video
        out.write(warped_frame);

        // Display the frame (optional)
        cv::imshow("Warp", warped_frame);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release everything
    cap.release();
    out.release();
    cv::destroyAllWindows();

    return 0;
}
