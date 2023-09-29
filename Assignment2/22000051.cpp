#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // Mat image_gray = imread("/Users/kimkwang-il/Desktop/opencv-setup/Lena.png", 0);
    Mat image_gray = imread("Lena.png", 0);
    Mat result = image_gray.clone();

    if (image_gray.empty())
    {
        cout << "don't find file" << endl;
        return -1;
    }

    int width = image_gray.cols;
    int height = image_gray.rows;

    // rotate
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            result.at<uchar>(y, x) = image_gray.at<uchar>(x, height - y - 1);
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            uchar pixel = result.at<uchar>(y, x);

            if (pixel < 127)
            {
                pixel = 255 - pixel;
            }
            else
            {
                pixel = saturate_cast<uchar>(pow(pixel / 255.0, 10) * 255.0);
            }
            result.at<uchar>(y, x) = pixel;
        }
    }

    imshow("gray image", image_gray);
    imshow("result", result);

    waitKey(0);

    return 0;
}