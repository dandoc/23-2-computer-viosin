#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

int main(void) {
    // 이미지를 그레이스케일로 불러오기
    Mat image = imread("lena.png", 0);

    // 결과 이미지를 저장할 Mat 객체 생성
    Mat result = image.clone();

    // 감마 값을 설정
    float gamma = 10;

    // 감마 테이블 생성
    unsigned char pix[256];
    for (int i = 0; i < 256; i++) {
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
    }

    // 감마 변환 수행
    for (int j = 0; j < image.rows; j++) {
        for (int i = 0; i < image.cols; i++) {
            // 뒤집기 먼저
            result.at<uchar>(image.cols - 1 - i, image.rows - 1 - j) = image.at<uchar>(image.rows - 1 - j, i);
    
            //// 여기 조건 넣기
            //if (result.at<uchar>(i, j) < 127) {
            //    // 부정 변환
            //    result.at<uchar>(image.cols - 1 - i, image.rows - j - 1) = 255 - result.at<uchar>(image.cols - 1 - i, image.rows - j - 1);
            //}
            //else {
            //    // 감마 연산 (r = 10)
            //    result.at<uchar>(image.cols - 1 - i, image.rows - j - 1) = pix[result.at<uchar>(image.cols - 1 - i, image.rows - j - 1)];
            //}
        }
    }

    //for (int j = 0; j < result.rows; j++) {
    //    for (int i = 0; i < result.cols; i++) {
    //        if (result.at<uchar>(j, i) < 127)
    //            result.at<uchar>(j, i) = 255 - result.at<uchar>(j, i);
    //    }
    //}
    for (int j = 0; j < result.rows; j++) {
        for (int i = 0; i < result.cols; i++) {
            // 여기 조건 넣기
            //result.at<uchar>(j, i) = 255 - result.at<uchar>(j, i);

            if (result.at<uchar>(j, i) < 127)
                result.at<uchar>(j, i) = 255 - result.at<uchar>(j, i);
            else        result.at<uchar>(j, i) = pix[result.at<uchar>(j, i)];

            //        //if (result.at<uchar>(j, i) < 127) {
            //        //    // 부정 변환
            //        //    result.at<uchar>(j, i) = 255 - result.at<uchar>(j, i);
            //        //}
            //        //else {
            //        //    // 감마 연산
            //        //    result.at<uchar>(j, i) = pix[result.at<uchar>(j, i)];
            //        //}
            //    }
            //}
        }
    }



    // 입력 이미지와 결과 이미지를 화면에 표시
    imshow("Input image", image);
    imshow("Result image", result);

    // 사용자가 키를 누를 때까지 대기
    waitKey(0);

    return 0;
}