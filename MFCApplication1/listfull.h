#pragma once
#include "resource.h"


// listfull 对话框

class listfull : public CDialogEx
{
	DECLARE_DYNAMIC(listfull)

public:
	listfull(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~listfull();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
