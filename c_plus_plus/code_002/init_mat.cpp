#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    // initial Mat
    // height, width, data_structure
    cv::Mat a(480, 640, CV_8UC3);
    std::cout << "a.size->" << a.size << "\ta.channel->" << a.channels() << std::endl;
    // shallow copy
    cv::Mat b = a;
    std::cout << "b.size->" << b.size << "\tb.channel->" << b.channels() << std::endl;
    // deep copy
    cv::Mat b_deepcopy = a.clone();
    std::cout << "b_deepcopy.size->" << b_deepcopy.size << "\tb_deepcopy.channel->" << b_deepcopy.channels() << std::endl;

    // Size()-> Size(width, height), data_structure
    cv::Mat c(cv::Size(640, 480), CV_8UC3, cv::Scalar(0, 0, 255)); // cv::Mat c(640, 480, CV_8UC3);
    std::cout << "c.size->" << c.size << "\tc.channel->" << c.channels() << std::endl;
    cv::imshow("red", c);
    cv::waitKey(0);


    return 0;
}