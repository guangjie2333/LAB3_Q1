
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/***************自定义的类调用***************/
#include  "USER_BAR_CLASS_DLG.h"
#include "USER_RGB_HSV_CLASS.h"
//#include "stdlib.h"

/***************内部变量声明***************/
bmpData bmpdata;



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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPENBMP, &CMFCApplication1Dlg::OnBnClickedButtonOpenbmp)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_HSV2RGB, &CMFCApplication1Dlg::OnBnClickedButtonHsv2rgb)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButtonOpenbmp()
{
	// TODO: 在此添加控件通知处理程序代码
	// 
	//打开文件 
	CString filter = (CString)"图像文件(*.bmp)|*.bmp;*.BMP||";//指明可供选择的文件类型和相应的扩展名
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);  //打开文件

//按下确定按钮 dlg.DoModal() 函数显示对话框
	if (dlg.DoModal() == IDOK)
	{
		//打开对话框获取图像信息
		CString BmpName = dlg.GetPathName();     //获取文件路径名   
		CString EntName = dlg.GetFileExt();      //获取文件扩展名
		EntName.MakeLower();                     //将文件扩展名转换为一个小写字符

		if (EntName.Compare(_T("bmp")) == 0)  //如果是bmp图片则打开显示
		{
			//定义变量存储图片信息
			BITMAPINFO* pBmpInfo;       //记录图像信息头内容
			

				//以只读的方式打开文件 读取bmp图片各部分 bmp文件头 信息 数据
			if (!bmpdata.bmpFile.Open(BmpName, CFile::modeRead | CFile::typeBinary))
				return;
			if (bmpdata.bmpFile.Read(&bmpdata.bmpHeader, sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
				return;
			if (bmpdata.bmpFile.Read(&bmpdata.bmpInfo, sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
				return;
			pBmpInfo = (BITMAPINFO*)new char[sizeof(BITMAPINFOHEADER)];
			//为图像数据申请空间
			memcpy(pBmpInfo, &bmpdata.bmpInfo, sizeof(BITMAPINFOHEADER));  //存储图像信息头内容
			DWORD dataBytes = bmpdata.bmpHeader.bfSize - bmpdata.bmpHeader.bfOffBits;//图像数据大小，单位为字节
			bmpdata.pBmpData = (BYTE*)new char[dataBytes];
			//bmpdata.bmpFile.Seek(bmpdata.bmpHeader.bfOffBits,0);//这一步非常重要，必须要把文件指针偏移
			bmpdata.bmpFile.Read(bmpdata.pBmpData, dataBytes);  //存储图像数据
			bmpdata.bmpFile.Close();

			//显示图像1	
			CWnd* pWnd = GetDlgItem(IDC_STATIC_PICTURE); //获得pictrue控件窗口的句柄			
			CRect rect;
			pWnd->GetClientRect(&rect); //获得pictrue控件所在的矩形区域			
			CDC* pDC = pWnd->GetDC(); //获得pictrue控件的DC			
			pDC->SetStretchBltMode(COLORONCOLOR);
			StretchDIBits(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, bmpdata.bmpInfo.biWidth, bmpdata.bmpInfo.biHeight, bmpdata.pBmpData, pBmpInfo, DIB_RGB_COLORS, SRCCOPY);
			
			////显示图像2	
			pWnd = GetDlgItem(IDC_STATIC_PICTURE2); //获得pictrue控件窗口的句柄			
			pWnd->GetClientRect(&rect); //获得pictrue控件所在的矩形区域			
			pDC = pWnd->GetDC(); //获得pictrue控件的DC			
			pDC->SetStretchBltMode(COLORONCOLOR);
			StretchDIBits(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, bmpdata.bmpInfo.biWidth, bmpdata.bmpInfo.biHeight, bmpdata.pBmpData, pBmpInfo, DIB_RGB_COLORS, SRCCOPY);
			
			//打印信息
			TRACE(" rect.Width() = %d , rect.Height() = %d, bmpInfo.biWidth = %d ,  bmpInfo.biHeight = %d \n\n",rect.Width(), rect.Height(), bmpdata.bmpInfo.biWidth, bmpdata.bmpInfo.biHeight);
			

		}
	}
}


void CMFCApplication1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//guangjie2333的设计
	//需要注意的是图像存在伸缩，需要更具伸缩比例确定

	CDialogEx::OnMouseMove(nFlags, point);

	CRect pect;

	CWnd* pWnd = GetDlgItem(IDC_STATIC_PICTURE);//IDC_PICTURE为控件ID号

	pWnd->GetClientRect(&pect);

	int high = pect.Height();   //返回高

	int width = pect.Width();   //返回宽


	TRACE("picture 控件长宽高信息  high = %d  width = %d \n\n" , high, width);


	//确保鼠标在图像内移动
	if ((point.x >= 12 && point.x <= 12 + width && point.y >= 76 && point.y <= 76 + high) || 
		(point.x >= 683 && point.x <= 683 + width && point.y >= 76 && point.y <= 76 + high))
	{
		TRACE("捕捉到了鼠标移动，当前位置 X = %d  Y = %d \n\n", point.x, point.y);
		SetDlgItemInt(IDC_EDIT_X, point.x);     //写入坐标值x
		SetDlgItemInt(IDC_EDIT_Y, point.y);     //写入坐标值y

		CWnd* pWnd = GetDlgItem(IDC_STATIC_PICTURE); //获得pictrue控件窗口的句柄
		CDC* pDC = pWnd->GetDC(); //获得pictrue控件的DC	
		HDC hDC = pDC->GetSafeHdc(); ;
		COLORREF rgb = ::GetPixel(hDC, point.x - 12, point.y - 76);  //相对坐标


		RGB_STRUCT rgbStruct;
		rgbStruct.r = GetRValue(rgb);     //获得灰度分量
		rgbStruct.g = GetGValue(rgb);
		rgbStruct.b = GetBValue(rgb);
		SetDlgItemInt(IDC_EDIT_R, rgbStruct.r);     //写入灰度分量R
		SetDlgItemInt(IDC_EDIT_G, rgbStruct.g);     //写入灰度分量G
		SetDlgItemInt(IDC_EDIT_B, rgbStruct.b);     //写入灰度分量B

		//显示该点的hsv值
		USER_RGB_HSV_CLASS userClass_rgb_hsv;
		HSV_STRUCT hsvStruct;
		hsvStruct = userClass_rgb_hsv.RGB2HSV(rgbStruct);

		CString str;
		SetDlgItemInt(IDC_EDIT_H, hsvStruct.h); //写入灰度分量R
		str.Format(_T("%.5f"), hsvStruct.s);
		SetDlgItemText(IDC_EDIT_S, str);        //写入灰度分量G
		str.Format(_T("%.5f"), hsvStruct.v);
		SetDlgItemText(IDC_EDIT_V, str);        //写入灰度分量B

	}
	else
	{
		SetDlgItemInt(IDC_EDIT_X, 0);     //写入坐标值x
		SetDlgItemInt(IDC_EDIT_Y, 0);     //写入坐标值y
		SetDlgItemInt(IDC_EDIT_R, 0);     //写入灰度分量R
		SetDlgItemInt(IDC_EDIT_G, 0);     //写入灰度分量G
		SetDlgItemInt(IDC_EDIT_B, 0);     //写入灰度分量B
		SetDlgItemInt(IDC_EDIT_H, 0);     //写入灰度分量H
		SetDlgItemInt(IDC_EDIT_S, 0);     //写入灰度分量S
		SetDlgItemInt(IDC_EDIT_V, 0);     //写入灰度分量V
	}
}


void CMFCApplication1Dlg::OnBnClickedButtonHsv2rgb()
{
	// TODO: 在此添加控件通知处理程序代码
	// 按键按下后做两件事 1.读取图像 2.打开新的对话框

	//将按键按下和新的Dialog联系
	USER_BAR_CLASS_DLG dlg;
	dlg.DoModal();
	while (1)
	{

	}

	                                   
}
