#pragma once
#include "Resource.h"


// kongDialog 对话框

class kongDialog : public CDialogEx
{
	DECLARE_DYNAMIC(kongDialog)

public:
	kongDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~kongDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
