// kongDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "kongDialog.h"
#include "afxdialogex.h"


// kongDialog 对话框

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


// kongDialog 消息处理程序
