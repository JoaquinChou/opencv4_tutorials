#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    const char *test_img_path = "./apple.jpg";
    cv::Mat img = cv::imread(test_img_path);
    if (img.empty())
    {
        std::cout << "Please check the image path" << std::endl;
        return -1;
    }
    cv::imshow("test", img);
    cv::waitKey(0);

    return 0;
}