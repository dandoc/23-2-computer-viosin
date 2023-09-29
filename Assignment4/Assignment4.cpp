#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat origin, gray;
    Mat left_ROI;
    Mat right_ROI;
    int del, left_LT_x, left_LT_y, left_RB_x, left_RB_y, right_LT_x, right_LT_y, right_RB_x, right_RB_y;
    left_LT_x = 200;
    left_LT_y = 400;
    left_RB_x = 600;
    left_RB_y = 600;

    right_LT_x = 600;
    right_LT_y = 400;
    right_RB_x = 1000;
    right_RB_y = 600;

    Rect rect_left(left_LT_x, left_LT_y, left_RB_x - left_LT_x, left_RB_y - left_LT_y);
    Rect rect_right(right_LT_x, right_LT_y, right_RB_x - right_LT_x, right_RB_y - right_LT_y);

    
/*
LT and RB of left_roi: (200,400) , (600,600)
LT and RB of right_roi: (600,400), (1000,600)
*/
    VideoCapture cp;

    if(cp.open("Road.mp4") == 0)
    {
        cout << "no such file!" << endl;
        waitKey(0);
    }

    del = 1000 / cp.get(CAP_PROP_FPS);

    namedWindow("Left canny");
    namedWindow("Right canny");


    while(1)
    {
        cp >> origin;
        if (origin.empty())
        {
            break;
        }
        cvtColor(origin, gray, CV_BGR2GRAY);
        GaussianBlur(gray, gray, Size(5.0f, 5.0f), 0);
        Canny(gray, gray, 10, 60, 3);
        left_ROI = gray(rect_left);
        right_ROI = gray(rect_right);

        moveWindow("Left canny", 200, 0);
        moveWindow("Right canny", 600, 0);
        imshow("Left canny", left_ROI);
        imshow("Right canny", right_ROI);

        waitKey(del);
    }
}
