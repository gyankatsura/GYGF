#pragma once
#include "afxwin.h"


// CAtlasEditor2 对话框

class CAtlasEditor2 : public CDialog
{
	DECLARE_DYNAMIC(CAtlasEditor2)

public:
	CAtlasEditor2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAtlasEditor2();
	int m_iLeft;
	int m_iTop;
	int m_iWidth;
	int m_iHeight;

// 对话框数据
	enum { IDD = IDD_ATLASEDITOR2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditl();
	afx_msg void OnEnChangeEditt();
	afx_msg void OnEnChangeEditw();
	afx_msg void OnEnChangeEdith();
	CEdit m_editLeft;
	CEdit m_editTop;
	CEdit m_editWidth;
	CEdit m_editHeight;
};
