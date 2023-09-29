#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("lena.png", 0);
    Mat result = image.clone();

    float gamma = 10;
    unsigned char pix[256];

    for(int i = 0; i < 256; i++){
        pix[i] = saturate_cast<uchar>(pow((float)(i/ 255.0), gamma) * 255.0f);
    }
    
    imshow("gray image",image);

    for(int j = 0; j < image.rows; j++){
        for(int i = 0; i < image.cols; i++){
            if(image.at<uchar>(i, j) < 127){
                result.at<uchar>(image.rows - j - 1, i) = 255 - image.at<uchar>(i, j);
            }
            else if(image.at<uchar>(i, j) >= 127){
                result.at<uchar>(image.rows - j - 1, i) = pix[image.at<uchar>(i, j)];
            }
        }
    }wor
        
    imshow("result",result);
   waitKey(0);
}
