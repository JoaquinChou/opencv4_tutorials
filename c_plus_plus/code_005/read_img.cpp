#include <iostream>
#include <opencv2/opencv.hpp>

void show_bgr_img(const std::string &img_path)
{
    // default_read：BGR
    cv::Mat img = cv::imread(img_path, cv::IMREAD_UNCHANGED);
    std::cout << "img->" << img.size << " x " << img.channels() << std::endl;
    // BGR->RGB
    // cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    // create the window to plot the img
    cv::namedWindow("lena", cv::WINDOW_NORMAL);
    cv::imshow("lena", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void show_gray_img(const std::string &img_path)
{
    cv::Mat gray_img = cv::imread(img_path, cv::IMREAD_GRAYSCALE);
    std::cout << "gray_img->" << gray_img.size << " x " << gray_img.channels() << std::endl;
    // create the window to plot the img
    cv::namedWindow("gray_lena", cv::WINDOW_NORMAL);
    cv::imshow("gray_lena", gray_img);
    cv::waitKey(0);
    cv::destroyAllWindows();

}

int main(int argc, char **argv)
{
    std::string img_path = "./lena.jpg";
    show_bgr_img(img_path);
    show_gray_img(img_path);



    return 0;
}