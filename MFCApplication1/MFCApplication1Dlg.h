
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

	int m_nTextX;   // ˮƽ�����ı�����ʼ���x����   
	int m_nTextY;   // ��ֱ�����ı�����ʼ���y����   
	CFont m_newFont;   // ������   
	CFont *m_pOldFont; // ѡ��������֮ǰ������

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


