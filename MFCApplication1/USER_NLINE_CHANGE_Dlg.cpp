// USER_NLINE_CHANGE_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "USER_NLINE_CHANGE_Dlg.h"
#include "afxdialogex.h"


// USER_NLINE_CHANGE_Dlg 对话框

IMPLEMENT_DYNAMIC(USER_NLINE_CHANGE_Dlg, CDialogEx)

USER_NLINE_CHANGE_Dlg::USER_NLINE_CHANGE_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NLINE, pParent)
{

}

USER_NLINE_CHANGE_Dlg::~USER_NLINE_CHANGE_Dlg()
{
}

void USER_NLINE_CHANGE_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(USER_NLINE_CHANGE_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &USER_NLINE_CHANGE_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// USER_NLINE_CHANGE_Dlg 消息处理程序


void USER_NLINE_CHANGE_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	CString str1, str2, str3;
	float a, b, c = 0; //获取编辑框中的整数值

	GetDlgItemText(IDC_EDIT_A, str1);
	GetDlgItemText(IDC_EDIT_B, str2);
	GetDlgItemText(IDC_EDIT_C, str2);

	a = _ttof(str1);
	b = _ttof(str2);
	c = _ttof(str3);

	NLINE_CHANGE_STRUCT nline_change_struct;
	nline_change_struct.a = a;
	nline_change_struct.b = b;
	nline_change_struct.c = c;

	::SendMessage(phwnd, WM_GET_DIALOG_NLINE_CHANGE_VAL, (WPARAM)&nline_change_struct, 0);
}
