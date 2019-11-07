
// boperationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "boperation.h"
#include "boperationDlg.h"
#include "afxdialogex.h"
#include<string>
#include<cmath>
#include"big.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CboperationDlg 对话框



CboperationDlg::CboperationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BOPERATION_DIALOG, pParent)
	, editv(_T(""))
	, resultv(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CboperationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, editv);
	DDX_Control(pDX, IDC_EDIT3, editc);
	DDX_Text(pDX, IDC_EDIT4, resultv);
	DDX_Control(pDX, IDC_EDIT4, resultc);
}

BEGIN_MESSAGE_MAP(CboperationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CboperationDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CboperationDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CboperationDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CboperationDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CboperationDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CboperationDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CboperationDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CboperationDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CboperationDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CboperationDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_rem, &CboperationDlg::OnBnClickedrem)
	ON_BN_CLICKED(IDC_Inv, &CboperationDlg::OnBnClickedInv)
	ON_BN_CLICKED(IDC_div, &CboperationDlg::OnBnClickeddiv)
	ON_BN_CLICKED(IDC_mul, &CboperationDlg::OnBnClickedmul)
	ON_BN_CLICKED(IDC_sub, &CboperationDlg::OnBnClickedsub)
	ON_BN_CLICKED(IDC_add, &CboperationDlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_AC, &CboperationDlg::OnBnClickedAc)
	ON_BN_CLICKED(IDC_back, &CboperationDlg::OnBnClickedback)
	ON_EN_CHANGE(IDC_EDIT4, &CboperationDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_equal, &CboperationDlg::OnBnClickedequal)
	ON_EN_CHANGE(IDC_EDIT3, &CboperationDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CboperationDlg 消息处理程序

BOOL CboperationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CboperationDlg::OnPaint()
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
HCURSOR CboperationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CboperationDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '0';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '1';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '2';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '3';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '4';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '5';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '6';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '7';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '8';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '9';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedrem()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '%';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedInv()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '^';
	UpdateData(false);
}


void CboperationDlg::OnBnClickeddiv()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '/';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedmul()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '*';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedsub()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '-';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedadd()
{
	// TODO: 在此添加控件通知处理程序代码
	editv += '+';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedAc()
{
	// TODO: 在此添加控件通知处理程序代码
	editv = "";
	UpdateData(false);
}


void CboperationDlg::OnBnClickedback()
{
	// TODO: 在此添加控件通知处理程序代码
	editv = editv.Left(editv.GetLength() - 1);
	UpdateData(false);

}


void CboperationDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CboperationDlg::OnBnClickedequal()
{
	// TODO: 在此添加控件通知处理程序代码
	int seat=1;//符号位置
	string str;
	string res;
	str = CW2A(editv.GetString());//CString转化为string
	string number1, number2;
	char ch;
	if (str.find_first_of('+')!=-1)
	{
		seat = str.find_first_of('+');
	}
	else if (str.find_first_of('-') != -1)
	{
		seat = str.find_first_of('-');
	}
	else if (str.find_first_of('*') != -1)
	{
		seat = str.find_first_of('*');
	}
	else if (str.find_first_of('/') != -1)
	{
		seat = str.find_first_of('/');
	}
	else
		res = "没有输入运算符!";
	if (seat != -1)
	{
		ch = str[seat];
		number1 = str.substr(0, seat);
		number2= str.substr(seat+1);
		big value;
		big(number1, ch, number2);
		res = value.get();

	}
	resultv = CA2W(res.c_str());//string转化为CString 	
	UpdateData(false);

}


void CboperationDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT3, editv);

}
