
// boperationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "boperation.h"
#include "boperationDlg.h"
#include "afxdialogex.h"
#include<string>
#include<cmath>
#include"big.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include<sstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CboperationDlg 对话框

CFont m_editFont;//字体全局变量
CboperationDlg::CboperationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BOPERATION_DIALOG, pParent)
	, editv(_T(""))
	, resultv(_T(""))
	, remainder(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cTest = new CTestDlg(this);
	
}

void CboperationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, editv);
	DDX_Control(pDX, IDC_EDIT3, editc);
	DDX_Text(pDX, IDC_EDIT4, resultv);
	DDX_Control(pDX, IDC_EDIT4, resultc);
	DDX_Text(pDX, IDC_EDIT5, remainder);
	DDX_Text(pDX, IDC_EDIT5, remainder);
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
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON30, &CboperationDlg::OnBnClickedButton30)
	ON_COMMAND(ID_32771, &CboperationDlg::newwin)
	ON_EN_CHANGE(IDC_EDIT5, &CboperationDlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CboperationDlg 消息处理程序

BOOL CboperationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_AC));
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	m_editFont.CreatePointFont(150, _T("宋体"));
	GetDlgItem(Operands1)->SetFont(&m_editFont);
	GetDlgItem(Operands2)->SetFont(&m_editFont);
	GetDlgItem(Operands3)->SetFont(&m_editFont); 
	GetDlgItem(IDC_EDIT3)->SetFont(&m_editFont);
	GetDlgItem(IDC_EDIT4)->SetFont(&m_editFont);
	GetDlgItem(IDC_EDIT5)->SetFont(&m_editFont); 
	GetDlgItem(IDC_AC)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON30)->SetFont(&m_editFont); 
	
	//editc.SetFont(&m_editFont);
	// TODO: 在此添加额外的初始化代码
	CRect rect;
	GetClientRect(&rect);//取客户区大小
	Old.x = rect.right - rect.left;
	Old.y = rect.bottom - rect.top;
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
	resultv = "";
	remainder="";

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
void stnum(string str, int &m) {
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '%')m=m+2;
		if (str[i] == '-')++m;
	}
}
void CboperationDlg::OnBnClickedequal()
{
	// TODO: 在此添加控件通知处理程序代码
	int seat=1;//符号位置
	int m = 0;
	string str;
	string result;//结果
	string remain;//余数
	str = CW2A(editv.GetString());//CString转化为string
	if (str.empty()) {
		AfxMessageBox(_T("请输入运算式！"));//错误处理
		return;
	}
	stnum(str, m);
	if (m > 3||str[0] == '+' || str[0] == '/' || str[0] == '*' || str[0] == '^' || str[0] == '%'
		|| str[str.length()-1] == '+' || str[str.length() - 1]=='-' || str[str.length() - 1] == '*'
		|| str[str.length() - 1] == '/' || str[str.length() - 1] == '^' || str[str.length() - 1] == '%') {
		AfxMessageBox(_T("请检查运算符！"));//错误处理
		return;

	}
	

	string number1, number2;//运算数
	char ch;//运算符
	if (str.find_first_of('+')!=-1)
	{
		seat = str.find_first_of('+');
	}

	else if (str.find_first_of('*') != -1)
	{
		seat = str.find_first_of('*');
	}
	else if (str.find_first_of('/') != -1)
	{
		seat = str.find_first_of('/');
	}
	else if (str.find_first_of('^') != -1)
	{
		seat = str.find_first_of('^');
	}
	else if (str.find_first_of('%') != -1)
	{
		seat = str.find_first_of('%');
	}
	else if (str.find_first_of('-', 1) != -1)//跳过负号
	{
		seat = str.find_first_of('-', 1);
	}
	else{
		AfxMessageBox(_T("没有输入运算符！"));
		return;
		}
	if (seat != -1)
	{
		ch = str[seat];
		number1 = str.substr(0, seat);
		number2= str.substr(seat+1);
		big value=big(number1, ch, number2);
		result = value.getresult();
		remain = value.getremain();

	}
	resultv = CA2W(result.c_str());//string转化为CString 	
	remainder = CA2W(remain.c_str());
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

void CboperationDlg::resize()
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / Old.x;
	fsp[1] = (float)Newp.y / Old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角
	CPoint OldBRPoint, BRPoint; //右下角
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	Old = Newp;

}

void CboperationDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	// TODO: Add your message handler code here
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED) {
		resize();
	}
}


void CboperationDlg::OnBnClickedButton30()
{
	// TODO: 在此添加控件通知处理程序代码
	std::fstream fs;
	std::ifstream ifs;

	fs.open("E://aaa//boperation//data//data.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fs.close();
	std::ofstream ofs;

	CString cstr1;
	GetDlgItem(IDC_EDIT3)->GetWindowText(cstr1);	
	string str1 ;
	str1 = CT2A(cstr1.GetString());

	CString cstr2;
	GetDlgItem(IDC_EDIT4)->GetWindowText(cstr2);
	string str2;
	str2 = CT2A(cstr2.GetString());

	CString cstr3;
	GetDlgItem(IDC_EDIT5)->GetWindowText(cstr3);
	string str3;
	str3 = CT2A(cstr3.GetString());


	//AfxMessageBox(cstr1+"保存成功！");
	ofs.open("E://aaa//boperation//data//data.txt", std::fstream::out | std::fstream::app);
	if (!ofs) {
		AfxMessageBox(_T("保存失败！"));
		return;
	}
	if (str1.empty() || str2.empty() || str3.empty()) {
		AfxMessageBox(_T("计算未完成！"));
		return;
	}
	ofs << str1+"   运算结果： "+str2+"   余数："+str3<< endl;
	ofs.close();
	AfxMessageBox(_T("保存成功！"));

}


void CboperationDlg::newwin()
{
	// TODO: 在此添加命令处理程序代码
	m_cTest->Create(IDD_DIALOG1, this);
	
}


void CboperationDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CboperationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	//判断m_hCcel是否为空
	
		
		if (::TranslateAccelerator(GetSafeHwnd(), hAccel, pMsg))
		{
			return true;
		}

		
	

	return CDialogEx::PreTranslateMessage(pMsg);
		
}
