
// boperationDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CboperationDlg �Ի���
class CboperationDlg : public CDialogEx
{
// ����
public:
	CboperationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOPERATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnStnClickedOperands1();
	afx_msg void OnStnClickedOperands2();
	CString editv;//�༭�ַ���
	CEdit editc;
	CString resultv;//���
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
	CString remainder;//����
};
