#pragma once

#include "USER_DEFINE.h"

// USER_NLINE_CHANGE_Dlg 对话框

class USER_NLINE_CHANGE_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(USER_NLINE_CHANGE_Dlg)

public:
	HWND phwnd;				//窗口变量，用于两个窗口之间传输值
	USER_NLINE_CHANGE_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~USER_NLINE_CHANGE_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NLINE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
