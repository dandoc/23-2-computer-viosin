#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat frame;
    int fps;
    int framecount;
    int framepos;
    int delay;
    VideoCapture cap;

    if (cap.open("background.mp4") == 0)
    {
        cout << "no such file!" << endl;
        waitKey(0);
    }

    fps = cap.get(CAP_PROP_FPS);
    delay = 1000 / fps;
    framecount = cap.get(CAP_PROP_FRAME_COUNT);
    while (1)
    {
        cap >> frame;
        framepos = cap.get(CAP_PROP_POS_FRAMES);
        if(frame.empty() || framepos == fps * 3)
        {
            cout << "end of video" << endl;
            break;
        }
        imshow("video", frame);
        cout << framepos << " / " << framecount <<endl;
        waitKey(delay);
    }
    
    // double time_in_mesc = cap.get(CAP_PROP_POS_MSEC);
    // int total_frames = cap.get(CAP_PROP_FRAME_COUNT);
}