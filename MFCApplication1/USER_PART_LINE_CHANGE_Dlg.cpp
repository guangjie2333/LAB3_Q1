// USER_PART_LINE_CHANGE_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "USER_PART_LINE_CHANGE_Dlg.h"
#include "afxdialogex.h"


// USER_PART_LINE_CHANGE_Dlg 对话框

IMPLEMENT_DYNAMIC(USER_PART_LINE_CHANGE_Dlg, CDialogEx)

USER_PART_LINE_CHANGE_Dlg::USER_PART_LINE_CHANGE_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PART_LINE, pParent)
{

}

USER_PART_LINE_CHANGE_Dlg::~USER_PART_LINE_CHANGE_Dlg()
{
}

void USER_PART_LINE_CHANGE_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(USER_PART_LINE_CHANGE_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &USER_PART_LINE_CHANGE_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()

 
// USER_PART_LINE_CHANGE_Dlg 消息处理程序


void USER_PART_LINE_CHANGE_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	PART_LINE_CHANGE_STRUCT part_line_change_struct;
	part_line_change_struct.a = GetDlgItemInt(IDC_EDIT_A);
	part_line_change_struct.b = GetDlgItemInt(IDC_EDIT_B);
	part_line_change_struct.c = GetDlgItemInt(IDC_EDIT_C);
	part_line_change_struct.d = GetDlgItemInt(IDC_EDIT_d);
	part_line_change_struct.Mf = GetDlgItemInt(IDC_EDIT_Mf);
	part_line_change_struct.Mg = GetDlgItemInt(IDC_EDIT_Mg);

	::SendMessage(phwnd, WM_GET_DIALOG_NLINE_CHANGE_VAL, (WPARAM)&part_line_change_struct, 0);
}
