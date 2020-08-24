#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void mapPixel(uint32_t,uint32_t,Vec3b&, Vec3b);
Vec3b reference;
bool frameSelect = false;
Mat image;

static void mouseHandler(int event,int x,int y, int flags,void* param) {
    Mat* frame = (Mat*) param;
    if( event == EVENT_LBUTTONDOWN ){
        frameSelect = true;
        reference = frame->at<Vec3b>(y,x);
    }
}

int main(int argc, char** argv){
    VideoCapture webcam;
    if(!webcam.open(0)) return 0;
    namedWindow("ImageDisplay", 1);
    image = imread("MyPic.jpg");

    for(;;) {
          Mat frame;
          webcam >> frame;
          setMouseCallback("ImageDisplay", mouseHandler, &frame);
          if (frameSelect) {
            for (uint32_t y = 0; y < frame.rows; y++) {
                for (uint32_t x = 0; x < frame.cols; x++) {
                    Vec3b& pixelColor = frame.at<Vec3b>(y,x);
                    mapPixel(x,y,pixelColor,reference);
                }
            }
          }
          if( frame.empty() ) break;
          imshow("ImageDisplay", frame);
          if( waitKey(10) == 27 ) break;
    }
    return 0;
}

void mapPixel(uint32_t x, uint32_t y, Vec3b& pixel, Vec3b reference) {
    if (pixel[0] == reference[0] and pixel[1] == reference[1] and pixel[2] == reference[2]) {
        Vec3b& pixelImage = image.at<Vec3b>(y,x);
        pixel[0] = pixelImage[0],pixel[1] = pixelImage[1],pixel[2] = pixelImage[2];
    }
} 
