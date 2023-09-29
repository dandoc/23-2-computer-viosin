#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat moon = imread("moon.jpeg", 0);
    int width, height;
    width = moon.cols;
    height = moon.rows;
    Rect rect_righthalf(width/2, 0, width/2, height);
    Mat moon_filtered = moon.clone();
    Mat moon_right = moon(rect_righthalf);
    Mat moon_blur;
    Mat moon_unsharp_mask;
    Mat moon_righthalf_filtered;

    GaussianBlur(moon_right, moon_blur, Size(0, 0), 1);
    subtract(moon_right, moon_blur, moon_unsharp_mask);
    add(moon_right, moon_unsharp_mask, moon_righthalf_filtered);

    for(int j = 0; j < moon_righthalf_filtered.rows; j++){
        for(int i = 0; i < moon_righthalf_filtered.cols; i++){
            moon_filtered.at<uchar>(j, i + moon_filtered.cols/2) = moon_righthalf_filtered.at<uchar>(j, i);
        }
    }
    imshow("moon", moon_unsharp_mask);
    imshow("moon_result", moon_filtered);

    // Mat moon1 = imread("moon.jpeg", 0);
    // width = moon1.cols;
    // height = moon1.rows;
    // Rect rect1_righthalf(width/2, 0, width/2, height);
    // Mat moon1_blur = moon1.clone();
    // moon1_blur = moon1_blur(rect1_righthalf);
    // Mat moon1_filtered = moon1.clone();
    // GaussianBlur(moon1_blur, moon1_blur, Size(0, 0), 1);
    // Mat moon1_blur1 = moon1_blur.clone();
    // Mat moon1_unsharp_mask = moon1.clone();
    // subtract(moon1, moon1_blur, moon1_unsharp_mask);
    // Mat moon1_unsharp_mask = moon1 - moon1_blur;
    // add(moon1, moon1_unsharp_mask, moon1_filtered);

    // imshow("aaa", moon1_filtered);

    
    Mat saltnpepper = imread("saltnpepper.png", 0);
    Mat saltnpepper_filtered = saltnpepper.clone();
    width = saltnpepper.cols;
    height = saltnpepper.rows;
    Rect rect_lefthalf(0, 0, width/2, height);
    Mat saltnpepper_lefthalf = saltnpepper(rect_lefthalf);
    Mat saltnpepper_blur;
    Mat saltnpepper_lefthalf_filtered;
    
    medianBlur(saltnpepper_lefthalf, saltnpepper_lefthalf_filtered, 9);
  
    for(int j = 0; j < saltnpepper_lefthalf_filtered.rows; j++){
        for(int i = 0; i < saltnpepper_lefthalf_filtered.cols; i++){
            saltnpepper_filtered.at<uchar>(j, i) = saltnpepper_lefthalf_filtered.at<uchar>(j, i);
        }
    }

    // imshow("saltnpepper", saltnpepper);`
    waitKey(0);
}
