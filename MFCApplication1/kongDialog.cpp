// kongDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "kongDialog.h"
#include "afxdialogex.h"


// kongDialog �Ի���

IMPLEMENT_DYNAMIC(kongDialog, CDialogEx)

kongDialog::kongDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(kongDialog::IDD, pParent)
{

}

kongDialog::~kongDialog()
{
}

void kongDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(kongDialog, CDialogEx)
END_MESSAGE_MAP()


// kongDialog ��Ϣ�������
