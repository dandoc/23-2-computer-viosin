#include "opencv2/opencv.hpp"

int main() {
    // 이미지를 그레이스케일로 불러오기
    cv::Mat image = cv::imread("lena.png", 0);

    // 결과 이미지를 저장할 Mat 객체 생성 (90도 회전 후 이미지 크기 고려)
    cv::Mat result(image.cols, image.rows, CV_8U);

    // 감마 값을 설정
    float gamma = 10;

    // 감마 테이블 생성
    unsigned char pix[256];
    for (int i = 0; i < 256; i++) {
        pix[i] = cv::saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
    }

    // 이미지를 90도 회전하여 result에 저장
    cv::rotate(image, result, cv::ROTATE_90_CLOCKWISE);

    // 이미지에 조건에 따라 부정 및 감마 변환 적용
    for (int j = 0; j < result.rows; j++) {
        for (int i = 0; i < result.cols; i++) {
            if (result.at<uchar>(j, i) < 127) {
                // 부정 변환
                result.at<uchar>(j, i) = 255 - result.at<uchar>(j, i);
            }
            else {
                // 감마 연산
                result.at<uchar>(j, i) = pix[result.at<uchar>(j, i)];
            }
        }
    }

    // 입력 이미지와 결과 이미지를 화면에 표시
    cv::imshow("Gray image", image);
    cv::imshow("Result", result);

    // 사용자가 키를 누를 때까지 대기
    cv::waitKey(0);

    return 0;
}