#pragma once
#include "Resource.h"


// kongDialog �Ի���

class kongDialog : public CDialogEx
{
	DECLARE_DYNAMIC(kongDialog)

public:
	kongDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~kongDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
