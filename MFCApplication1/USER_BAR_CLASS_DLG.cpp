﻿// USER_BAR_CLASS_DLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "USER_BAR_CLASS_DLG.h"
#include "afxdialogex.h"




// USER_BAR_CLASS_DLG 对话框

IMPLEMENT_DYNAMIC(USER_BAR_CLASS_DLG, CDialogEx)

//构造函数，也是初始化函数
USER_BAR_CLASS_DLG::USER_BAR_CLASS_DLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

USER_BAR_CLASS_DLG::~USER_BAR_CLASS_DLG()
{
}

void USER_BAR_CLASS_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_V, m_SliderV);
	DDX_Control(pDX, IDC_SLIDER_S, m_SliderS);
	DDX_Control(pDX, IDC_SLIDER_H, m_SliderH);



}


BEGIN_MESSAGE_MAP(USER_BAR_CLASS_DLG, CDialogEx)
	ON_WM_HSCROLL()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// USER_BAR_CLASS_DLG 消息处理程序





void USER_BAR_CLASS_DLG::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	UpdateData(TRUE);

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CSliderCtrl* pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_H);
	//m_int 即为当前滑块的值。
	int m_int =  pSlidCtrl->GetPos();//取得当前位置值  
	SetDlgItemInt(IDC_EDIT_Slider_H, m_int); //很奇怪，显示报错还能正常运行

	pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_S);
	m_int = pSlidCtrl->GetPos();//取得当前位置值  
	SetDlgItemInt(IDC_EDIT_Slider_S, m_int);

	pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_V);
	m_int = pSlidCtrl->GetPos();//取得当前位置值  
	SetDlgItemInt(IDC_EDIT_Slider_V, m_int);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	UpdateData(FALSE);

}



BOOL USER_BAR_CLASS_DLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_SliderH.SetRange(0, 100);//设置滑动范围为1到100
	m_SliderS.SetRange(0, 100);//设置滑动范围为1到100
	m_SliderV.SetRange(0, 100);//设置滑动范围为1到100

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}








