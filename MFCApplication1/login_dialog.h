#pragma once
#include "afxwin.h"
#include "Resource.h"


// login_dialog �Ի���

class login_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(login_dialog)

public:
	login_dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~login_dialog();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_zhanghao;
	CString m_password;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	int m_high;
};
