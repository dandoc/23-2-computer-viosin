#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat moon = imread("Moon.jpeg", 0);
    int width, height;
    width = moon.cols;
    height = moon.rows;
    Mat moon_filtered = moon.clone();
    Rect rect_righthalf(width/2, 0, width/2, height);
    Mat moon_right = moon_filtered(rect_righthalf);
    Mat moon_blur, unshape_mask;

    GaussianBlur(moon_right, moon_blur, Size(3, 3), 1);
    subtract(moon_right, moon_blur, unshape_mask);
    add(moon_right, unshape_mask, moon_right);

    imshow("moon", moon);
    imshow("moon_filtered", moon_filtered);

    Mat saltnpepper = imread("saltnpepper.png", 0);
    width = saltnpepper.cols;
    height = saltnpepper.rows;
    Mat saltnpepper_filtered = saltnpepper.clone();
    Rect rect_lefthalf(0, 0, width/2, height);
    Mat saltnpepper_left = saltnpepper_filtered(rect_lefthalf);

    medianBlur(saltnpepper_left, saltnpepper_left, 9);

    imshow("saltnpepper", saltnpepper);
    imshow("saltnpepper_filtered", saltnpepper_filtered);

    waitKey(0);
}
