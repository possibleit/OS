#pragma once
#include "resource.h"


// MyDialog1 �Ի���

class MyDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog1)

public:
	MyDialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog1();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
