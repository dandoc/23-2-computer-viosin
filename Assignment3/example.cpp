#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image, laplacian, abs_laplacian, sharpening;
    image = imread("moon.jpeg", 0);

    GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);

    Laplacian(image, laplacian, CV_16S, 1, 1, 0);
    convertScaleAbs(laplacian, abs_laplacian);
    sharpening = abs_laplacian + image;

    imshow("Imput image", image);
    imshow("Laplacian", laplacian);
    imshow("abs_Laplacian", abs_laplacian);
    imshow("Sharpening", sharpening);

    waitKey(0);

    return 0;
}