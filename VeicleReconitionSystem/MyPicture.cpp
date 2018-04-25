#include "stdafx.h"
#include "MyPicture.h"
#include "MyFunctions.h"


void MyPicture::loadRGBImage(string imagePath, CString cImagePath, cv::Size rectSize) {
	MyFunctions *functions = new MyFunctions();
	Mat opencvRGBImageReSize;
	opencvRGBImage = imread(imagePath);
	opencvIplImage = cvLoadImage(CT2CA(cImagePath), 1);
	cv::resize(opencvRGBImage, opencvRGBImageReSize, rectSize);
	functions->MatToCImage(opencvRGBImageReSize, cRGBImage);
	imageWidth = cRGBImage.GetWidth();
	imageHeight = cRGBImage.GetHeight();
}

void MyPicture::show(HWND IDC_PICTURE) {
}

void MyPicture::setOpencvRGBImage(Mat rGBImage)
{
	opencvRGBImage = rGBImage;
}

void MyPicture::setCRGBImage(CImage rGBImage)
{
	cRGBImage = rGBImage;
}

void MyPicture::setUnfinisImage(IplImage *rUnFinishImage)
{
	unFinishImage = rUnFinishImage;
}

void MyPicture::setOpencvIplImage(IplImage *rIplImage)
{
	opencvIplImage = rIplImage;
}

Mat MyPicture::getOpencvRGBImage()
{
	return this->opencvRGBImage;
}

CImage MyPicture::getCRGBImage()
{
	return this->cRGBImage;
}

IplImage* MyPicture::getUnfinisImage()
{
	return this->unFinishImage;
}

IplImage* MyPicture::getOpencvIplImage()
{
	return this->opencvIplImage;
}

int MyPicture::getImageWidth()
{
	return this->imageHeight;
}

int MyPicture::getImageHeight()
{
	return this->imageWidth;
}
