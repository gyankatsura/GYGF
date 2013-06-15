#pragma once
#include "afxwin.h"


// CAtlasEditor2 �Ի���

class CAtlasEditor2 : public CDialog
{
	DECLARE_DYNAMIC(CAtlasEditor2)

public:
	CAtlasEditor2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAtlasEditor2();
	int m_iLeft;
	int m_iTop;
	int m_iWidth;
	int m_iHeight;

// �Ի�������
	enum { IDD = IDD_ATLASEDITOR2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
