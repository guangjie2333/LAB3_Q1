// USER_LINE_CHANGE_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "USER_LINE_CHANGE_Dlg.h"
#include "afxdialogex.h"

//用户自定义头文件
#include "USER_DEFINE.h"


// USER_LINE_CHANGE_Dlg 对话框

IMPLEMENT_DYNAMIC(USER_LINE_CHANGE_Dlg, CDialogEx)

USER_LINE_CHANGE_Dlg::USER_LINE_CHANGE_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LINER, pParent)
{

}

USER_LINE_CHANGE_Dlg::~USER_LINE_CHANGE_Dlg()
{
}

void USER_LINE_CHANGE_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(USER_LINE_CHANGE_Dlg, CDialogEx)
	ON_COMMAND(ID_32774, &USER_LINE_CHANGE_Dlg::Button_Up)
	ON_BN_CLICKED(IDOK, &USER_LINE_CHANGE_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// USER_LINE_CHANGE_Dlg 消息处理程序


void USER_LINE_CHANGE_Dlg::Button_Up()
{
	// TODO: 在此添加命令处理程序代码
	
}


void USER_LINE_CHANGE_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	/*
	1.按键按下，获取编辑文本框中的值
	2.除此之外，还需要判断一下输入的值是否为整数，不是整数就弹出一个提示框
	3.点击确定按钮后直接退出程序
	4.线性变换：y = a * x + b
	*/


	//检查系数a
	CString str;

	GetDlgItem(IDC_EDIT_A)->GetWindowText(str);

	char c;

	for (int i = 0; i < str.GetLength(); i++)

	{
		c = str.GetAt(i);

		if (c >= '0' && c <= '9')
		{

		}
		else
		{
			MessageBox("please input a intger number"); 
		}

	}

	//检查系数b
	GetDlgItem(IDC_EDIT_B)->GetWindowText(str);
	for (int i = 0; i < str.GetLength(); i++)

	{
		c = str.GetAt(i);

		if (c >= '0' && c <= '9')
		{

		}
		else
		{
			MessageBox("please input a intger number");
		}

	}

	/*
	如果没有触发MessageBox就可以顺利执行到这
	接下来要做的事情：1.接收编辑框中的值 2.把值传递给主界面
	*/

	int a ,b = 0; //获取编辑框中的整数值
	a = GetDlgItemInt(IDC_EDIT_A);
	b = GetDlgItemInt(IDC_EDIT_B);

	LINE_CHANGE_STRUCT line_change_struct;
	line_change_struct.a = a;
	line_change_struct.b = b;

	::SendMessage(phwnd, WM_GET_DIALOG_HSV_SLIDER_VAL, (WPARAM)&line_change_struct, 0);
}
