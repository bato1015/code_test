#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void square(double center_x,double center_y,double widge,double hight);
void line();

cv::Mat image = cv::Mat::zeros(cv::Size(1080,780), CV_8UC3);

struct vec{
    
};


int main()
{
    for(int i=0;i<20;i++){
        //cv::line(image, cv::Point(50*i, 0), cv::Point(400*i, 300), cv::Scalar(0, 0, 255), 2, cv::LINE_4);
        //cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
    }
    square(0.5*1080,780-15,15,14);
    cv::imshow("drawing", image);
    cv::waitKey(0);
    return 0;
}

void square(double center_x,double center_y,double widge,double hight){
    widge*=0.5;
    hight*=0.5;
    cv::line(image, cv::Point(center_x-widge, center_y+hight), cv::Point(center_x+(widge), center_y+hight), cv::Scalar(0, 0, 255), 1, cv::LINE_8);
    cv::line(image, cv::Point(center_x+widge, center_y+hight), cv::Point(center_x+widge, center_y-hight), cv::Scalar(0, 0, 255), 1, cv::LINE_8);
    cv::line(image, cv::Point(center_x+widge, center_y-hight), cv::Point(center_x-widge, center_y-hight), cv::Scalar(0, 0, 255), 1, cv::LINE_8);
    cv::line(image, cv::Point(center_x-widge, center_y-hight), cv::Point(center_x-widge, center_y+hight), cv::Scalar(0, 0, 255), 1, cv::LINE_8);
}