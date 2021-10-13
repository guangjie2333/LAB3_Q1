﻿
// MFCApplication1Dlg.h: 头文件
//

#pragma once
#include "USER_DEFINE.h"


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenbmp();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonHsv2rgb();
	LRESULT UserMessageHandler_HSV(WPARAM w, LPARAM l); //自己定义的消息处理函数
	LRESULT UserMessageHandler_LINE(WPARAM w, LPARAM l); //自己定义的消息处理函数
	LRESULT UserMessageHandler_NLINE(WPARAM w, LPARAM l); //自己定义的消息处理函数
	afx_msg void MEUN_LAB3_Button1_Up();
	afx_msg void MEUN_LAB3_Button2_Up();
	afx_msg void MEUN_LAB3_Button3_Up();
};
