
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "Resource.h"

#include "jincheng.h"
#include "string.h"
#include "stdio.h"
#include "kongDialog.h"
#include "listfull.h"
#include "login_dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_p(0)
	, m_r(0)
	, m_w(0)
	, m_bool(0)
	, m_s(0)
	, m_STROUT(_T(""))
	, m_string_out(_T(""))
	, m_hangup(_T(""))
	, m_reserve(_T(""))
	, m_block(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nTextX = 10;                    //在这修改位置信息
	m_nTextY = 10;
	m_pOldFont = NULL;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_p);
	DDX_Text(pDX, IDC_EDIT2, m_r);
	DDX_Text(pDX, IDC_EDIT3, m_w);
	DDX_Text(pDX, IDC_EDIT5, m_bool);
	DDV_MinMaxInt(pDX, m_p, 0, INT_MAX);
	DDV_MinMaxInt(pDX, m_r, 0, INT_MAX);
	DDV_MinMaxInt(pDX, m_w, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT6, m_s);
	DDV_MinMaxInt(pDX, m_s, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT4, m_STROUT);
	DDX_Text(pDX, IDC_EDIT8, m_string_out);
	DDX_Text(pDX, IDC_EDIT7, m_hangup);
	DDX_Text(pDX, IDC_EDIT9, m_reserve);
	DDX_Text(pDX, IDC_EDIT10, m_block);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT8, &CMFCApplication1Dlg::OnEnChangeEdit8)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_newFont.CreatePointFont(120, _T("楷书"));                         //在这修改

	// 设置定时器，定时时间为200ms   
	SetTimer(1, 2000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CPaintDC dc(this); // device context for painting                       //在这修改
		// 设置m_newFont对象的字体为当前字体，并将之前的字体指针保存到m_pOldFont  
		


		init1(weight_list);
		init2(SUB_LIST);
		init(reserve_list);



		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


UINT CMFCApplication1Dlg::Thread(void *param)
{
	CMFCApplication1Dlg  *dlg = (CMFCApplication1Dlg*)param;
	std::string str2;
	str2 = refresh2(SUB_LIST);
	dlg->m_string_out = str2.c_str();
	return 0;
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	PSA(weight_list);
	std::vector<PCB>::iterator it;
	if (weight_list.empty())
	{
		INT_PTR nRes;
		kongDialog tipDlg;
		nRes = tipDlg.DoModal();
		if (IDCANCEL == nRes)
			return;
		select(reserve_list, weight_list);
	}
	it = weight_list.begin();
	m_p = (*it).PID;
	m_r = (*it).RunTime;
	m_w = (*it).weight;
	m_s = (*it).size;
	
	std::string str;
	str = refresh(weight_list);
	m_STROUT = str.c_str();

	std::string str2;
	str2 = refresh2(SUB_LIST);
	m_string_out = str2.c_str();

	std::string sstr;
	sstr = refresh(hang_up_list);
	m_hangup = sstr.c_str();

	std::string astr;
	astr = refresh(reserve_list);
	m_reserve = astr.c_str();
	m_bool++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (weight_list.size() == 3)
	{
		INT_PTR nRes;
		listfull tipDlg;
		nRes = tipDlg.DoModal();
		if (IDOK == nRes || IDCANCEL == nRes)
			return;
	}
	add(reserve_list, m_p, m_r, m_w, m_s, 0);
	sort(weight_list.begin(), weight_list.end(), weight_down);
	m_bool++;
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	hang_up(weight_list, m_p, hang_up_list);
	std::string sstr;
	sstr = refresh(hang_up_list);
	m_hangup = sstr.c_str();
	UpdateData(FALSE);
}

void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//std::string str2;
	//str2 = refresh2(SUB_LIST);
	//m_string_out = str2.c_str();
	m_bool++;
	
	//AfxBeginThread(Thread, this);
	//UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication1Dlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Reset_hang_up(weight_list, m_p, hang_up_list);
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!ss)
	{
		block(weight_list, m_p, block_list);
		ss = 1;
	}
	else{
		reblock(weight_list, m_p, block_list);
		ss = 0;
	}
	std::string aastr;
	aastr = refresh(block_list);
	m_block = aastr.c_str();

	std::string str;
	str = refresh(weight_list);
	m_STROUT = str.c_str();
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	INT_PTR nRes;
	login_dialog tipDlg;
	nRes = tipDlg.DoModal();
	if (IDOK == nRes || IDCANCEL == nRes)
		return;
}
