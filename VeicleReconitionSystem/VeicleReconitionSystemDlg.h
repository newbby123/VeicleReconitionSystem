
// VeicleReconitionSystemDlg.h: 头文件
//
#include "MyPicture.h"

#pragma once


// CVeicleReconitionSystemDlg 对话框
class CVeicleReconitionSystemDlg : public CDialogEx
{
// 构造
public:
	CVeicleReconitionSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VEICLERECONITIONSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CStatic* pWnd;
	MyPicture BCKPicture; //背景图像
	MyPicture OBJPicture; //原图像
	MyPicture RSTPicture; //识别结果图像
	IplImage *BkImg;
	IplImage *BkGray;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtLoadgrp();
	afx_msg void showPicture(MyPicture picture);
	afx_msg void showResultPicture(MyPicture picture);
	afx_msg std::string CStringToSTDStr(const CString& theCStr);
	afx_msg void OnBnClickedBtLoadobp();
	afx_msg void showIMLPicture(IplImage* img, UINT ID);
	afx_msg void OnBnClickedBtSub();
	afx_msg void OnBnClickedBtBinary();
	afx_msg void OnBnClickedBtOpen();
	afx_msg void OnBnClickedBtRemovenoise();
	afx_msg void OnBnClickedBtFill();
};
