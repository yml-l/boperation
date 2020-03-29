
// boperationDlg.cpp : ʵ���ļ�
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


// CboperationDlg �Ի���

CFont m_editFont;//����ȫ�ֱ���
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


// CboperationDlg ��Ϣ�������

BOOL CboperationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_AC));
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	m_editFont.CreatePointFont(150, _T("����"));
	GetDlgItem(Operands1)->SetFont(&m_editFont);
	GetDlgItem(Operands2)->SetFont(&m_editFont);
	GetDlgItem(Operands3)->SetFont(&m_editFont); 
	GetDlgItem(IDC_EDIT3)->SetFont(&m_editFont);
	GetDlgItem(IDC_EDIT4)->SetFont(&m_editFont);
	GetDlgItem(IDC_EDIT5)->SetFont(&m_editFont); 
	GetDlgItem(IDC_AC)->SetFont(&m_editFont);
	GetDlgItem(IDC_BUTTON30)->SetFont(&m_editFont); 
	
	//editc.SetFont(&m_editFont);
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rect;
	GetClientRect(&rect);//ȡ�ͻ�����С
	Old.x = rect.right - rect.left;
	Old.y = rect.bottom - rect.top;
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
	resultv = "";
	remainder="";

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
void stnum(string str, int &m) {
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '%')m=m+2;
		if (str[i] == '-')++m;
	}
}
void CboperationDlg::OnBnClickedequal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int seat=1;//����λ��
	int m = 0;
	string str;
	string result;//���
	string remain;//����
	str = CW2A(editv.GetString());//CStringת��Ϊstring
	if (str.empty()) {
		AfxMessageBox(_T("����������ʽ��"));//������
		return;
	}
	stnum(str, m);
	if (m > 3||str[0] == '+' || str[0] == '/' || str[0] == '*' || str[0] == '^' || str[0] == '%'
		|| str[str.length()-1] == '+' || str[str.length() - 1]=='-' || str[str.length() - 1] == '*'
		|| str[str.length() - 1] == '/' || str[str.length() - 1] == '^' || str[str.length() - 1] == '%') {
		AfxMessageBox(_T("�����������"));//������
		return;

	}
	

	string number1, number2;//������
	char ch;//�����
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
	else if (str.find_first_of('-', 1) != -1)//��������
	{
		seat = str.find_first_of('-', 1);
	}
	else{
		AfxMessageBox(_T("û�������������"));
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
	resultv = CA2W(result.c_str());//stringת��ΪCString 	
	remainder = CA2W(remain.c_str());
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

void CboperationDlg::resize()
{
	float fsp[2];
	POINT Newp; //��ȡ���ڶԻ���Ĵ�С
	CRect recta;
	GetClientRect(&recta);     //ȡ�ͻ�����С  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / Old.x;
	fsp[1] = (float)Newp.y / Old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //���Ͻ�
	CPoint OldBRPoint, BRPoint; //���½�
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ�  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//ȡ��ID
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

	// TODO: �ڴ˴������Ϣ����������
	// TODO: Add your message handler code here
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED) {
		resize();
	}
}


void CboperationDlg::OnBnClickedButton30()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


	//AfxMessageBox(cstr1+"����ɹ���");
	ofs.open("E://aaa//boperation//data//data.txt", std::fstream::out | std::fstream::app);
	if (!ofs) {
		AfxMessageBox(_T("����ʧ�ܣ�"));
		return;
	}
	if (str1.empty() || str2.empty() || str3.empty()) {
		AfxMessageBox(_T("����δ��ɣ�"));
		return;
	}
	ofs << str1+"   �������� "+str2+"   ������"+str3<< endl;
	ofs.close();
	AfxMessageBox(_T("����ɹ���"));

}


void CboperationDlg::newwin()
{
	// TODO: �ڴ���������������
	m_cTest->Create(IDD_DIALOG1, this);
	
}


void CboperationDlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CboperationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	//�ж�m_hCcel�Ƿ�Ϊ��
	
		
		if (::TranslateAccelerator(GetSafeHwnd(), hAccel, pMsg))
		{
			return true;
		}

		
	

	return CDialogEx::PreTranslateMessage(pMsg);
		
}
