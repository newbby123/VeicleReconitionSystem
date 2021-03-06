
// VeicleReconitionSystemDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "VeicleReconitionSystem.h"
#include "VeicleReconitionSystemDlg.h"
#include "afxdialogex.h"
#include "MyFunctions.h"
#include "CvvImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVeicleReconitionSystemDlg 对话框



CVeicleReconitionSystemDlg::CVeicleReconitionSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VEICLERECONITIONSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVeicleReconitionSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVeicleReconitionSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_LOADGRP, &CVeicleReconitionSystemDlg::OnBnClickedBtLoadgrp)
	ON_BN_CLICKED(IDC_BT_LOADOBP, &CVeicleReconitionSystemDlg::OnBnClickedBtLoadobp)
	ON_BN_CLICKED(IDC_BT_SUB, &CVeicleReconitionSystemDlg::OnBnClickedBtSub)
	ON_BN_CLICKED(IDC_BT_BINARY, &CVeicleReconitionSystemDlg::OnBnClickedBtBinary)
	ON_BN_CLICKED(IDC_BT_OPEN, &CVeicleReconitionSystemDlg::OnBnClickedBtOpen)
	ON_BN_CLICKED(IDC_BT_REMOVENOISE, &CVeicleReconitionSystemDlg::OnBnClickedBtRemovenoise)
	ON_BN_CLICKED(IDC_BT_FILL, &CVeicleReconitionSystemDlg::OnBnClickedBtFill)
END_MESSAGE_MAP()


// CVeicleReconitionSystemDlg 消息处理程序

BOOL CVeicleReconitionSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CVeicleReconitionSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVeicleReconitionSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVeicleReconitionSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVeicleReconitionSystemDlg::OnBnClickedBtLoadgrp()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		NULL, this);   //选择文件对话框
	CString imagePath;
	if (dlg.DoModal() == IDOK)
	{
		imagePath = dlg.GetPathName();  //获取视频文件路径   
	}
	pWnd = (CStatic*)GetDlgItem(IDC_BCG_PICTURE);
	CRect rect;
	string path = CT2CA(imagePath.GetString());
	pWnd->GetClientRect(&rect);
	BCKPicture.loadRGBImage(path, imagePath, cv::Size(rect.Width(), rect.Height()));
	BkImg = cvLoadImage(CT2CA(dlg.GetPathName()), 1);
	showPicture(BCKPicture);
}

void CVeicleReconitionSystemDlg::OnBnClickedBtLoadobp()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT,
		_T("image files (*.bmp; *.jpg) |*.bmp; *.jpg | All Files (*.*) |*.*||"), this);   //选择文件对话框
	CString imagePath;
	if (dlg.DoModal() == IDOK)
	{
		imagePath = dlg.GetPathName();  //获取视频文件路径   
	}
	pWnd = (CStatic*)GetDlgItem(IDC_OBJ_PICTURE);
	CRect rect;
	string path = CT2CA(imagePath.GetString());
	pWnd->GetClientRect(&rect);
	OBJPicture.loadRGBImage(path, imagePath, cv::Size(rect.Width(), rect.Height()));
	showPicture(OBJPicture);
}

void CVeicleReconitionSystemDlg::showPicture(MyPicture picture) {
	CDC * pDc = pWnd->GetWindowDC();
	CRect rect;
	pWnd->GetClientRect(&rect);
	picture.getCRGBImage().Draw(pDc->m_hDC, rect);
	ReleaseDC(pDc);
}

void CVeicleReconitionSystemDlg::showResultPicture(MyPicture picture) {
	CDC *pDC = GetDlgItem(IDC_RES_PICTURE)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(IDC_RES_PICTURE)->GetClientRect(&rect);

	CvvImage cimg;
	cimg.CopyOf(picture.unFinishImage);        // 复制图片
	cimg.DrawToHDC(hDC, &rect); // 绘制到控件
	ReleaseDC(pDC);
}
void CVeicleReconitionSystemDlg::showIMLPicture(IplImage* img, UINT ID) {

	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);

	CvvImage cimg;
	cimg.CopyOf(img);        // 复制图片
	cimg.DrawToHDC(hDC, &rect); // 绘制到控件
	ReleaseDC(pDC);
}

std::string CVeicleReconitionSystemDlg::CStringToSTDStr(const CString& theCStr)
{
	const int theCStrLen = theCStr.GetLength();
	char *buffer = (char*)malloc(sizeof(char)*(theCStrLen + 1));
	memset((void*)buffer, 0, sizeof(buffer));
	WideCharToMultiByte(CP_UTF8, 0, static_cast<CString>(theCStr).GetBuffer(), theCStrLen, buffer, sizeof(char)*(theCStrLen + 1), NULL, NULL);

	std::string STDStr(buffer);
	free((void*)buffer);
	return STDStr;
}



void CVeicleReconitionSystemDlg::OnBnClickedBtSub()
{
	// TODO: 在此添加控件通知处理程序代码
	//将图像首先转化为灰度图像
	BCKPicture.unFinishImage = cvCreateImage(cvGetSize(BCKPicture.opencvIplImage), 8, 1);
	cvCvtColor(BCKPicture.opencvIplImage, BCKPicture.unFinishImage, CV_BGR2GRAY);
	OBJPicture.unFinishImage = cvCreateImage(cvGetSize(OBJPicture.opencvIplImage), 8, 1);
	cvCvtColor(OBJPicture.opencvIplImage, OBJPicture.unFinishImage, CV_BGR2GRAY);

	//对图像进行高斯平滑操作
	cvSmooth(BCKPicture.unFinishImage, BCKPicture.unFinishImage, CV_GAUSSIAN, 5);
	cvSmooth(OBJPicture.unFinishImage, OBJPicture.unFinishImage, CV_GAUSSIAN, 5);

	//对图像进行做差运算
	RSTPicture.unFinishImage = cvCreateImage(cvGetSize(BCKPicture.opencvIplImage), 8, 1);
	cvAbsDiff(OBJPicture.unFinishImage, BCKPicture.unFinishImage, RSTPicture.unFinishImage);

	showResultPicture(RSTPicture);
}


void CVeicleReconitionSystemDlg::OnBnClickedBtBinary()
{
	// TODO: 在此添加控件通知处理程序代码
	//图像二值化
	cvThreshold(RSTPicture.unFinishImage, RSTPicture.unFinishImage, 0, 255, CV_THRESH_OTSU);

	showResultPicture(RSTPicture);
}


void CVeicleReconitionSystemDlg::OnBnClickedBtOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	//定义腐蚀和膨胀用的核,
	IplConvKernel * kernel_5_5;
	kernel_5_5 = cvCreateStructuringElementEx(5, 5, 2, 2, CV_SHAPE_ELLIPSE, 0);
	IplConvKernel * kernel_7_7;
	kernel_7_7 = cvCreateStructuringElementEx(7, 7, 3, 3, CV_SHAPE_ELLIPSE, 0);

	//对前景图像进行开闭合运算以除去杂点，分割出运动物体
	//对图像进行腐蚀运算
	cvErode(RSTPicture.unFinishImage, RSTPicture.unFinishImage, kernel_5_5, 1);

	//对图像进行膨胀运算
	cvDilate(RSTPicture.unFinishImage, RSTPicture.unFinishImage, kernel_7_7, 1);

	showResultPicture(RSTPicture);
}


void CVeicleReconitionSystemDlg::OnBnClickedBtRemovenoise()
{
	// TODO: 在此添加控件通知处理程序代码
	//去除较小的离散连通区域

	//首先将图像复制一份
	IplImage * BinaryImg2;
	BinaryImg2 = cvCloneImage(RSTPicture.unFinishImage);

	// 定义内存空间
	CvMemStorage * storage = cvCreateMemStorage(0);

	//定义统计联通区域轮廓的序列
	CvSeq * area_contour = NULL;
	int Number_contours = 0;   //轮廓个数
	double Area = 0;           //轮廓面积
	CvScalar s_fill_new;
	s_fill_new.val[0] = 0;
	CvScalar loDiff;
	loDiff.val[0] = 10;
	CvScalar upDiff;
	upDiff.val[0] = 10;
	//查找图像中的最外部轮廓
	Number_contours = cvFindContours(RSTPicture.unFinishImage, storage, &area_contour, sizeof(CvContour), CV_RETR_EXTERNAL);
	//统计轮廓面积，对于面积小于阈值的进行删除
	for (CvSeq * c = area_contour; c != NULL; c = c->h_next)
	{
		//获得轮廓面积
		Area = fabs(cvContourPerimeter(c));
		if (Area<30)
		{
			for (int i = 0; i<1; i++)
			{
				//取轮廓上的一个点作为图像填充种子点
				CvPoint * seedpoint = CV_GET_SEQ_ELEM(CvPoint, c, i);
				//用漫水填充算法将小的轮廓填充为背景色
				cvFloodFill(BinaryImg2, *seedpoint, s_fill_new, loDiff, upDiff, NULL, 4, 0);
			}
		}
	}
	RSTPicture.unFinishImage = cvCloneImage(BinaryImg2);

	showResultPicture(RSTPicture);
}


void CVeicleReconitionSystemDlg::OnBnClickedBtFill()
{
	// TODO: 在此添加控件通知处理程序代码
	//对汽车进行内部填充
	CvScalar s;
	CvScalar s_new;
	s_new.val[0] = 255;
	//记录填充行的最左位置
	int left_X = 0;
	//记录填充行的最右位置
	int right_X = 0;
	//记录填充列的最上位置
	int top_Y = 0;
	//记录填充列的最下位置
	int bottom_Y = 0;

	//纵向填充
	for (int wt = 0; wt<RSTPicture.unFinishImage->width; wt++)
	{
		for (int ht = 0; ht<RSTPicture.unFinishImage->height; ht++)
		{
			s = cvGet2D(RSTPicture.unFinishImage, ht, wt);
			if (255 == s.val[0])
			{
				top_Y = ht;//找到最上边的白色点
				for (int m = RSTPicture.unFinishImage->height - 1; m >= 0; m--)
				{
					s = cvGet2D(RSTPicture.unFinishImage, m, wt);
					if (255 == s.val[0])
					{
						bottom_Y = m;
						break; //跳出寻找最下边点的循环
					}
				}
				//将top_Y与bottom_Y之间的点设置为白色
				for (int i = top_Y; i <= bottom_Y; i++)
					cvSet2D(RSTPicture.unFinishImage, i, wt, s_new);
				ht = RSTPicture.unFinishImage->height;//强制跳出此列循环
			}
		}
	}

	//横向填充
	for (int ht = 0; ht<RSTPicture.unFinishImage->height; ht++)
	{
		for (int wt = 0; wt<RSTPicture.unFinishImage->width; wt++)
		{
			s = cvGet2D(RSTPicture.unFinishImage, ht, wt);
			if (255 == s.val[0])
			{
				left_X = wt;//找到最左边的白色点
				for (int m = RSTPicture.unFinishImage->width - 1; m >= 0; m--)
				{
					s = cvGet2D(RSTPicture.unFinishImage, ht, m);
					if (255 == s.val[0])
					{
						right_X = m;
						break; //跳出寻找最右边点的循环
					}
				}
				//将left_X与right_X之间的点设置为白色
				for (int i = left_X; i <= right_X; i++)
					cvSet2D(RSTPicture.unFinishImage, ht, i, s_new);
				wt = RSTPicture.unFinishImage->width;//强制跳出此行循环
			}
		}
	}

	showResultPicture(RSTPicture);
}
