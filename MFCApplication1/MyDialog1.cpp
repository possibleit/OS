// MyDialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDialog1.h"
#include "afxdialogex.h"


// MyDialog1 对话框

IMPLEMENT_DYNAMIC(MyDialog1, CDialogEx)

MyDialog1::MyDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog1::IDD, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

MyDialog1::~MyDialog1()
{
}

void MyDialog1::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void MyDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog1, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(MyDialog1, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IMyDialog1 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {F8E6BE6B-8864-449B-8C87-42547B0B9B66}
static const IID IID_IMyDialog1 =
{ 0xF8E6BE6B, 0x8864, 0x449B, { 0x8C, 0x87, 0x42, 0x54, 0x7B, 0xB, 0x9B, 0x66 } };

BEGIN_INTERFACE_MAP(MyDialog1, CDialogEx)
	INTERFACE_PART(MyDialog1, IID_IMyDialog1, Dispatch)
END_INTERFACE_MAP()


// MyDialog1 消息处理程序
