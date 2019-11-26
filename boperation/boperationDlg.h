
// boperationDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CboperationDlg 对话框
class CboperationDlg : public CDialogEx
{
// 构造
public:
	CboperationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOPERATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnStnClickedOperands1();
	afx_msg void OnStnClickedOperands2();
	CString editv;//编辑字符串
	CEdit editc;
	CString resultv;//结果
	CEdit resultc;
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedrem();
	afx_msg void OnBnClickedInv();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedmul();
	afx_msg void OnBnClickedsub();
	afx_msg void OnBnClickedadd();
	afx_msg void OnBnClickedAc();
	afx_msg void OnBnClickedback();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedequal();
	afx_msg void OnEnChangeEdit3();
	CString remainder;//余数
};
