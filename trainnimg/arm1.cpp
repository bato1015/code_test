#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    cv::Mat image = cv::Mat::zeros(cv::Size(500, 500), CV_8UC3);
    for(int i=0;i<20;i++){
    cv::line(image, cv::Point(50*i, 0), cv::Point(400*i, 300), cv::Scalar(0, 0, 255), 2, cv::LINE_4);
    //cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
    }
  cv::imshow("drawing", image);
  cv::waitKey(0);
    return 0;
}

void war(){
    
}
