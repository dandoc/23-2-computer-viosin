#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image;
    Mat hist_equalized_image;

    image = imread("lena.png", 0);
    if(!image.data) exit(1);

    equalizeHist(image, hist_equalized_image);
    imshow("Input", image);
    imshow("output", hist_equalized_image);


    waitKey(0);

    return 0;
}