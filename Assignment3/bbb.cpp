
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
   
   Mat image = imread("moon.jpeg", 0);
   Mat unsharpening = Mat::zeros(image.size(), image.type());
   Mat image2 = image.clone();
   Mat half = image.clone();
   Mat blink = Mat::zeros(image.size(), image.type());
   int k = 1;
   //Mat addImage = imread("Moon.png", 0);
   GaussianBlur(image2, image2, Size(3, 3), 1);
   unsharpening = image - image2;
   half = image + k * unsharpening;
   
   Rect left = Rect(0, 0, image.cols/2, image.rows);
   Mat leftImage = image(left);
   Rect right = Rect(half.cols/2, 0, half.cols/2, half.rows);
   Mat rightImage = image(right);

   Mat addImage=Mat::zeros(image.size(), image.type());
   //add(image, rightImage, addImage);
   for (int j = 0; j < image.cols / 2; j++) { // 왼쪽 반의 가로 크기만큼 반복
      for (int i = 0; i < image.rows; i++) {
         addImage.at<uchar>(i, j) = leftImage.at<uchar>(i, j);
      }
   }

   for (int j = 0; j < image.cols / 2; j++) { // 오른쪽 반의 가로 크기만큼 반복
      for (int i = 0; i < image.rows; i++) {
         addImage.at<uchar>(i, image.cols / 2 + j) = rightImage.at<uchar>(i, j);
      }
   }
   
   
   imshow("Sharpening", addImage);
   imshow("image", image);
   imshow("aaa", image - addImage);
   imshow("bbb", addImage-image);
   waitKey(0);
   return 0;
}