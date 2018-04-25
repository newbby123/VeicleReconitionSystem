// VeicleReconitionSystem.h: 程序涉及的函数
//
#include <opencv2\highgui\highgui.hpp>
#include <atlimage.h>

#pragma once

using namespace cv;
using namespace std;

class MyFunctions {

public:
	MyFunctions();
	void MatToCImage(Mat &mat, CImage &cImage);
};