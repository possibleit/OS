// MyDialog1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDialog1.h"
#include "afxdialogex.h"


// MyDialog1 �Ի���

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IMyDialog1 ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {F8E6BE6B-8864-449B-8C87-42547B0B9B66}
static const IID IID_IMyDialog1 =
{ 0xF8E6BE6B, 0x8864, 0x449B, { 0x8C, 0x87, 0x42, 0x54, 0x7B, 0xB, 0x9B, 0x66 } };

BEGIN_INTERFACE_MAP(MyDialog1, CDialogEx)
	INTERFACE_PART(MyDialog1, IID_IMyDialog1, Dispatch)
END_INTERFACE_MAP()


// MyDialog1 ��Ϣ�������
