// listfull.cpp : 实现文件
//

#include "stdafx.h"
#include "listfull.h"
#include "afxdialogex.h"


// listfull 对话框

IMPLEMENT_DYNAMIC(listfull, CDialogEx)

listfull::listfull(CWnd* pParent /*=NULL*/)
	: CDialogEx(listfull::IDD, pParent)
{

}

listfull::~listfull()
{
}

void listfull::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(listfull, CDialogEx)
END_MESSAGE_MAP()


// listfull 消息处理程序
