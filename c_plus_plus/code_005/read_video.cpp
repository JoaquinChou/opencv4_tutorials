#include <iostream>
#include <opencv2/opencv.hpp>

// define videoinfo struct
struct VideoInfo
{
    int width;
    int height;
    float fps;
    int total_frame_num;
};

VideoInfo get_video_info(cv::VideoCapture &vc)
{
    VideoInfo info;
    info.width = vc.get(cv::CAP_PROP_FRAME_WIDTH);
    info.height = vc.get(cv::CAP_PROP_FRAME_HEIGHT);
    info.fps = vc.get(cv::CAP_PROP_FPS);
    info.total_frame_num = vc.get(cv::CAP_PROP_FRAME_COUNT);

    return info;
}

int show_video(const std::string &vid_name)
{
    cv::VideoCapture vc(vid_name);
    if (not vc.isOpened())
    {
        std::cout << "Please check the video name" << std::endl;
        return -1;
    }
    VideoInfo info = get_video_info(vc);
    std::cout << "the width of the video is " << info.width << std::endl;
    std::cout << "the height of the video is " << info.height << std::endl;
    std::cout << "the fps of the video is " << info.fps << std::endl;
    std::cout << "the total frame number of the video is " << info.total_frame_num << std::endl;

    while (true)
    {
        cv::Mat frame;
        vc >> frame;
        if (frame.empty())
        {
            break;
        }
        cv::namedWindow("cup video", cv::WINDOW_NORMAL);
        cv::imshow("cup video", frame);
        // 1s = 1000ms, waitKey for millisecond
        cv::waitKey(1000 / info.fps);
    }
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

int main(int argc, char **argv)
{
    std::string vid_name = "./cup.mp4";
    return show_video(vid_name);
}