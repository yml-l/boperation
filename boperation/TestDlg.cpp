// TestDlg.cpp : ʵ���ļ�
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
// CTestDlg �Ի���

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

	while (infile.getline(line, sizeof(line)))//��ȡ��������
	{
	
		stringstream word(line);
		while (getline(word, tmp))//�ԣ�Ϊ�ָ�������ȡ����
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


// CTestDlg ��Ϣ�������
void CTestDlg::Show()
{
	// TODO: �ڴ���������������
	
}




void CTestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnCancel();
	DestroyWindow();
}


void CTestDlg::OnBnClickedCancel3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char line[10000];
	std::fstream fs;
	std::ifstream ifs;
	ifstream infile("E://aaa//boperation//data//data.txt", ios::in);

	string tmp;
	CString resuh;

	while (infile.getline(line, sizeof(line)))//��ȡ��������
	{

		stringstream word(line);
		while (getline(word, tmp))//�ԣ�Ϊ�ָ�������ȡ����
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTestDlg::OnEnChangerem()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTestDlg::OnBnClickedCancel2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int result = MessageBox(TEXT("ȷ�������ʷ��¼��"), TEXT("�½�����"), MB_YESNO);

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
