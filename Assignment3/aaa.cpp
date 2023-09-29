#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
   Mat image, laplacian, abs_laplacian, sharpening, unsharpened_mask, blur;
   Mat make_sharp;    // 이건 unsharped를 image 전체에 적용한 사진
   //image = imread("./Computer_Vision_dataset/moon.jpeg", 0);
   image = imread("moon.png", 0);

   int width = image.cols;
   int height = image.rows;   // h - r

   GaussianBlur(image, blur, Size(3, 3), 0, 0, BORDER_DEFAULT);
   subtract(image, blur, unsharpened_mask);
   add(image, unsharpened_mask, make_sharp);

   Mat result_mask = Mat::zeros(image.size(), image.type());
   
   Rect origin_rect(width / 2, 0, width / 2, height);
   Mat origin_mask = image.clone();
   origin_mask(origin_rect).setTo(Scalar(0));

   Rect filtered_rect(0, 0, width / 2, height);
   Mat filtered_mask = make_sharp.clone();
   filtered_mask(filtered_rect).setTo(Scalar(0));
   add(origin_mask, filtered_mask, result_mask);
   imshow("moon", image);

   imshow("moon_filtered", result_mask);

   imshow("aaaa", result_mask - image);

   Mat _image = imread("saltnpepper.png", 0);
   imshow("saltnpepper", _image);

   int _width = _image.cols; 
   int _height = _image.rows;

   Rect _origin_rect(0, 0, _width / 2, _height);
   Mat _origin_mask = _image.clone();
   _origin_mask(_origin_rect).setTo(Scalar(0));

   Mat mf;
   medianBlur(_image, mf, 9);

   Rect _filtered_rect(_width/2, 0, _width / 2, _height);
   Mat _filtered_mask = mf.clone();
   _filtered_mask(_filtered_rect).setTo(Scalar(0)); 

   Mat _result_mask = Mat::zeros(_image.size(), _image.type());
   add(_origin_mask, _filtered_mask, _result_mask);
   
   imshow("saltnpepper_filtered", _result_mask);

   waitKey(0);

   return 0;
}