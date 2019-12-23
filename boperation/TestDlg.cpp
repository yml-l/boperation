// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "boperation.h"
#include "TestDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include<sstream>
using namespace std;
// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, Hoper(_T(""))
{
	char line[10000];
	std::fstream fs;
	std::ifstream ifs;
	ifstream infile("E://aaa//boperation//data//data.txt", ios::in);

	string tmp;
	CString resuh;

	while (infile.getline(line, sizeof(line)))//读取该行数据
	{
	
		stringstream word(line);
		while (getline(word, tmp))//以，为分隔符，读取数据
		{
			resuh = resuh + CA2W(tmp.c_str());
		}
		
		resuh = resuh + _T("\r\n") + _T("\r\n")
			+ _T("=======================================================================================================================================")
			+ _T("\r\n") + _T("\r\n") ;
	}
	Hoper = resuh;
	
}

CTestDlg::~CTestDlg()
{
	
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_re, Hoper);
	
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_COMMAND(ID_32771, &CTestDlg::Show)
	ON_BN_CLICKED(IDCANCEL, &CTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL3, &CTestDlg::OnBnClickedCancel3)
	ON_EN_CHANGE(IDC_re, &CTestDlg::OnEnChangere)
	ON_EN_CHANGE(IDC_rem, &CTestDlg::OnEnChangerem)
	ON_BN_CLICKED(IDCANCEL2, &CTestDlg::OnBnClickedCancel2)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序
void CTestDlg::Show()
{
	// TODO: 在此添加命令处理程序代码
	
}




void CTestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnCancel();
	DestroyWindow();
}


void CTestDlg::OnBnClickedCancel3()
{
	// TODO: 在此添加控件通知处理程序代码
	char line[10000];
	std::fstream fs;
	std::ifstream ifs;
	ifstream infile("E://aaa//boperation//data//data.txt", ios::in);

	string tmp;
	CString resuh;

	while (infile.getline(line, sizeof(line)))//读取该行数据
	{

		stringstream word(line);
		while (getline(word, tmp))//以，为分隔符，读取数据
		{
			resuh = resuh + CA2W(tmp.c_str());
		}

		resuh = resuh + _T("\r\n") + _T("\r\n")
			+ _T("=======================================================================================================================================")
			+ _T("\r\n") + _T("\r\n");
	}
	Hoper=resuh;
	UpdateData(false);
}


void CTestDlg::OnEnChangere()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTestDlg::OnEnChangerem()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTestDlg::OnBnClickedCancel2()
{
	// TODO: 在此添加控件通知处理程序代码

	int result = MessageBox(TEXT("确定清空历史记录吗？"), TEXT("新建任务"), MB_YESNO);

	switch (result)
	{
	case IDYES:
	{
		
		fstream fss("E://aaa//boperation//data//data.txt", fstream::out | ios_base::trunc);
		OnBnClickedCancel3();
		break;
	}
	case IDNO:
	
		break;
	}
	
}
