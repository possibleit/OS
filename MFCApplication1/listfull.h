#pragma once
#include "resource.h"


// listfull �Ի���

class listfull : public CDialogEx
{
	DECLARE_DYNAMIC(listfull)

public:
	listfull(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~listfull();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
