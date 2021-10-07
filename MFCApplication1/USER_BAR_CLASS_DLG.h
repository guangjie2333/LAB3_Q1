#pragma once
#include "USER_DEFINE.h"

// USER_BAR_CLASS_DLG 对话框

class USER_BAR_CLASS_DLG : public CDialogEx
{
public:
	CSliderCtrl	m_SliderV; //声明3个滚动条变量
	CSliderCtrl	m_SliderS;
	CSliderCtrl	m_SliderH;

	HWND phwnd;				//窗口变量，用于两个窗口之间传输值

	DECLARE_DYNAMIC(USER_BAR_CLASS_DLG)

public:
	USER_BAR_CLASS_DLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~USER_BAR_CLASS_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	
};
