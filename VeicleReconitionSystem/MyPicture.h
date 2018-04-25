#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <atlimage.h>

#pragma once

using namespace cv;
using namespace std;

class MyPicture {
private:
	int imageWidth, imageHeight;
	
public:
	Mat opencvRGBImage;
	CImage cRGBImage;
	IplImage *opencvIplImage;
	IplImage *unFinishImage;


	void loadRGBImage(string imagePath, CString cImagePath, cv::Size rectSize);
	void show(HWND IDC_PICTURE);
	void setOpencvRGBImage(Mat rGBImage);
	void setCRGBImage(CImage rGBImage);
	void setUnfinisImage(IplImage *rUnFinishImage);
	void setOpencvIplImage(IplImage *rIplImage);
	Mat getOpencvRGBImage();
	CImage getCRGBImage();
	IplImage* getUnfinisImage();
	IplImage* getOpencvIplImage();
	int getImageWidth();
	int getImageHeight();
};