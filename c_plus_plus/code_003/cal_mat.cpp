#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat init_a()
{
    cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

    return a;
}

cv::Mat loop_init_b()
{
    cv::Mat b = cv::Mat_<int>(3, 3);
    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            b.at<int>(i, j) = i + j;
        }
    }

    return b;
}

cv::Mat cv_method_init_c()
{
    // Identity Matrix
    // cv::Mat c = cv::Mat::eye(3, 3, CV_8UC1);

    // Ones Matrix
    // cv::Mat c = cv::Mat::ones(3, 3, CV_8UC1);

    // Zero Matrix
    // cv::Mat c = cv::Mat::zeros(3, 3, CV_8UC1);

    // Diagonal Matrix
    cv::Mat diag = (cv::Mat_<int>(1, 3) << 1, 2, 3);
    cv::Mat c = cv::Mat::diag(diag);

    return c;
}

cv::Mat array_method_init_d()
{
    cv::Mat d = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);

    return d;
}

int main(int argc, char **argv)
{
    // Enumeration method assignment a
    cv::Mat a = init_a();
    std::cout << "a->" << a << std::endl;

    // loop method assignment b
    cv::Mat b = loop_init_b();
    std::cout << "b->" << b << std::endl;

    // cv method assignment c
    cv::Mat c = cv_method_init_c();
    std::cout << "c->" << c << std::endl;

    // array method assignment d
    cv::Mat d = array_method_init_d();
    std::cout << "d->" << d << std::endl;

    // Basic operations: +, -, * /
    cv::Mat add_a_b, sub_a_b, sub_a_1, multi_a, multi_d, div_d;
    add_a_b = a + b;
    std::cout << "a+b->" << add_a_b << std::endl;

    sub_a_b = a - b;
    std::cout << "a-b->" << sub_a_b << std::endl;

    sub_a_1 = a - 1;
    std::cout << "a-1->" << sub_a_1 << std::endl;

    multi_a = 2.3 * a;
    std::cout << "2.3*a->" << multi_a << std::endl;

    multi_d = 2 * d;
    std::cout << "2*d->" << multi_d << std::endl;


    // matrix multiplication operation: the type of Mat must be float or double
    cv::Mat matrix_multi_d_d;
    matrix_multi_d_d = d*d;
    std::cout << "d*d->" << matrix_multi_d_d << std::endl;

    // vector dot operation: the input matrix would be reshaped to one vector to calculate the inner product
    // the inner product is a double num
    double vector_dot_a_c;
    vector_dot_a_c = a.dot(c);
    std::cout << "a.dot(c)->" << vector_dot_a_c << std::endl;

    // Corresponding element multiplication operation: the type of output Mat is the same as input Mat in default
    cv::Mat element_mul_a_c;
    element_mul_a_c = a.mul(c);
    std::cout << "element_mul_a_c->" << element_mul_a_c << std::endl;

    return 0;
}