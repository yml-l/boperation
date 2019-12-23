#pragma once


// CTestDlg 对话框

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDlg();
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
