#pragma once


// CTestDlg �Ի���

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg();
	

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Show();
	afx_msg void OnBnClickedCancel();
	CString Hoper;
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnEnChangere();
	
	afx_msg void OnEnChangerem();
	afx_msg void OnBnClickedCancel2();
};
