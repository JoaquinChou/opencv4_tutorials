#include <iostream>
#include <opencv2/opencv.hpp>

void read_mat()
{
    cv::Mat a = cv::Mat(3, 4, CV_32FC3);
    std::cout << "a->" << a << std::endl;
    // cols rows channel
    std::cout << "a_cols->" << a.cols << "\ta_rows->" << a.rows << "\ta_channel->" << a.channels() << std::endl;
    // the num of per channel's matrix (BGR)
    std::cout << "a_total_num->" << a.total() << std::endl;
    // the byte of each element [float(32 bit)] -> 32/8*3
    std::cout << "the byte of a_element->" << a.elemSize() << std::endl;
    // the byte of one row element -> elemSize()*cols
    std::cout << "the byte of one row element->" << a.step << std::endl;
}

void read_mat_ele()
{
    // 1. at method read element in mat
    std::cout << "--------1. at method read element in mat--------" << std::endl;
    // cv::Vec3b, cv::Vec3s, cv::Vec3w, cv::Vec3i, cv::Vec3f, cv::Vec3d
    cv::Mat a = cv::Mat(3, 4, CV_8UC3, cv::Scalar(255, 255, 255));
    // get (0,0) element
    cv::Vec3b vc3 = a.at<cv::Vec3b>(0, 0);
    std::cout << "the (0,0) of the element->" << vc3 << std::endl;
    int first = (int)vc3.val[0];
    int second = (int)vc3.val[1];
    int third = (int)vc3.val[2];
    std::cout << "vc3_first->" << first << std::endl;
    std::cout << "vc3_second->" << second << std::endl;
    std::cout << "vc3_third->" << third << std::endl;

    // init a mat call b
    std::cout << "--------init a mat call b--------" << std::endl;
    cv::Mat b = cv::Mat(3, 4, CV_8UC3);
    int value = 0;
    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            for (int k = 0; k < b.channels(); k++)
            {
                b.at<cv::Vec3b>(i, j)[k] = value;
                value++;
            }
        }
    }

    // 2. read by ptr -> (int)b.ptr(i)[j]
    std::cout << "--------2. read by ptr -> (int)b.ptr(i)[j]--------" << std::endl;

    for (int i = 0; i < b.rows; i++)
    {
        std::cout << (i+1) << " row status:" << std::endl;
        for (int j = 0; j < b.cols * b.channels(); j++)
        {
            std::cout << "read by ptr->" << (int)b.ptr(i)[j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < b.rows; i++)
    {
        uchar *ptr = b.ptr<uchar>(i);
        for (int j = 0; j < b.cols; j++)
        {
            cv::Vec3b pixel = b.at<cv::Vec3b>(i, j);
            std::cout << "per channel num->" << (int)pixel[0] << " " << (int)pixel[1]
                      << " " << (int)pixel[2] << std::endl;
        }
    }

    // 3. read by iterator
    std::cout << "--------3. read by iterator--------" << std::endl;
    cv::MatIterator_<uchar> it = b.begin<uchar>();
    cv::MatIterator_<uchar> it_end = b.end<uchar>();
    for (int i = 0; it != it_end; it++)
    {
        std::cout << "read by iterator->" << (int)(*it) << " ";
        if (++i % b.cols == 0)
        {
            std::cout << std::endl;
        }
    }

    // 4. read by row x col x per_channel
    std::cout << "--------4. read by row x col x channel--------" << std::endl;
    // get the element in 2x1x3
    int r=1, c=0, channel=2;
    int res = (int)(*(b.data + b.step[0]*r + b.step[1]*c + channel));
    std::cout << "b[1][0]->" << res << std::endl;


}

int main(int args, char **argv)
{
    read_mat_ele();

    return 0;
}