// VeicleReconitionSystem.h: �����漰�ĺ���
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