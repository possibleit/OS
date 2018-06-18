
// MFCApplication1Dlg.h : 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int m_p;
	int m_r;
	int m_w;
	afx_msg void OnBnClickedButton3();
	int m_bool;
	int m_s;

	int m_nTextX;   // 水平滚动文本的起始点的x坐标   
	int m_nTextY;   // 垂直滚动文本的起始点的y坐标   
	CFont m_newFont;   // 新字体   
	CFont *m_pOldFont; // 选择新字体之前的字体

	LPCWSTR str;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_STROUT;
	afx_msg void OnEnChangeEdit8();
	CString m_string_out;


	static UINT Thread(void *param);
	CString m_hangup;
	CString m_reserve;
	afx_msg void OnBnClickedButton4();
	CString m_block;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};


