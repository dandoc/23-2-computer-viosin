#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image_gray = imread("Lena.png", 0);
    Mat result = image_gray.clone();

    float gamma = 10;
    if (image_gray.empty())
    {
        cout << "don't find file" << endl;
        return -1;
    }

    int width = image_gray.cols;
    int height = image_gray.rows;

    rotate(result, result, ROTATE_90_COUNTERCLOCKWISE);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            uchar pixel = result.at<uchar>(y, x); // 그레이스케일 이미지에서 픽셀 값 가져오기

            // 픽셀 값이 127보다 작으면 음수 변환 수행
            if (pixel < 127)
            {
                pixel = 255 - pixel;
            }
            else
            { // 아니면 감마 변환 수행 (감마를 10으로 설정)
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