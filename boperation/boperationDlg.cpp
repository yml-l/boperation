
// boperationDlg.cpp : ʵ���ļ�
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


// CboperationDlg �Ի���



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


// CboperationDlg ��Ϣ�������

BOOL CboperationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CboperationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CboperationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CboperationDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '0';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '1';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '2';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '3';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '4';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '5';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '6';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '7';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '8';
	UpdateData(false);
}


void CboperationDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '9';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedrem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '%';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedInv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '^';
	UpdateData(false);
}


void CboperationDlg::OnBnClickeddiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '/';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedmul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '*';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedsub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '-';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv += '+';
	UpdateData(false);
}


void CboperationDlg::OnBnClickedAc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv = "";
	UpdateData(false);
}


void CboperationDlg::OnBnClickedback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	editv = editv.Left(editv.GetLength() - 1);
	UpdateData(false);

}


void CboperationDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CboperationDlg::OnBnClickedequal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int seat=1;//����λ��
	string str;
	string res;
	str = CW2A(editv.GetString());//CStringת��Ϊstring
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
		res = "û�����������!";
	if (seat != -1)
	{
		ch = str[seat];
		number1 = str.substr(0, seat);
		number2= str.substr(seat+1);
		big value;
		big(number1, ch, number2);
		res = value.get();

	}
	resultv = CA2W(res.c_str());//stringת��ΪCString 	
	UpdateData(false);

}


void CboperationDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT3, editv);

}
