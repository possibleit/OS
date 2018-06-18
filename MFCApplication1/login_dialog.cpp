// login_dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "login_dialog.h"
#include "afxdialogex.h"


// login_dialog �Ի���

IMPLEMENT_DYNAMIC(login_dialog, CDialogEx)

login_dialog::login_dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(login_dialog::IDD, pParent)
	, m_zhanghao(_T(""))
	, m_password(_T(""))
	, m_high(0)
{

}

login_dialog::~login_dialog()
{
}

void login_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_zhanghao);
	DDV_MaxChars(pDX, m_zhanghao, 16);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDV_MaxChars(pDX, m_password, 16);
}


BEGIN_MESSAGE_MAP(login_dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &login_dialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &login_dialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// login_dialog ��Ϣ�������


void login_dialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	char ch[16];
	sprintf_s(ch, "%d", m_high);
	m_zhanghao = ch;
	UpdateData(FALSE);
}


void login_dialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
