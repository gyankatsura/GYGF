// AtlasEditor2.cpp : 实现文件
//

#include "stdafx.h"
#include "AtlasMaker.h"
#include "AtlasEditor2.h"


// CAtlasEditor2 对话框

IMPLEMENT_DYNAMIC(CAtlasEditor2, CDialog)

CAtlasEditor2::CAtlasEditor2(CWnd* pParent /*=NULL*/)
	: CDialog(CAtlasEditor2::IDD, pParent)
	, m_iLeft(0)
	, m_iTop(0)
	, m_iWidth(0)
	, m_iHeight(0)
{

}

CAtlasEditor2::~CAtlasEditor2()
{
}

void CAtlasEditor2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITL, m_editLeft);
	DDX_Control(pDX, IDC_EDITT, m_editTop);
	DDX_Control(pDX, IDC_EDITW, m_editWidth);
	DDX_Control(pDX, IDC_EDITH, m_editHeight);
}


BEGIN_MESSAGE_MAP(CAtlasEditor2, CDialog)
	ON_EN_CHANGE(IDC_EDITL, &CAtlasEditor2::OnEnChangeEditl)
	ON_EN_CHANGE(IDC_EDITT, &CAtlasEditor2::OnEnChangeEditt)
	ON_EN_CHANGE(IDC_EDITW, &CAtlasEditor2::OnEnChangeEditw)
	ON_EN_CHANGE(IDC_EDITH, &CAtlasEditor2::OnEnChangeEdith)
END_MESSAGE_MAP()

BOOL CAtlasEditor2::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString str;
	str.Format("%d", m_iLeft);
	m_editLeft.SetWindowText(str.GetBuffer());
	str.Format("%d", m_iTop);
	m_editTop.SetWindowText(str.GetBuffer());
	str.Format("%d", m_iWidth);
	m_editWidth.SetWindowText(str.GetBuffer());
	str.Format("%d", m_iHeight);
	m_editHeight.SetWindowText(str.GetBuffer());
	return TRUE;
}

// CAtlasEditor2 消息处理程序

void CAtlasEditor2::OnEnChangeEditl()
{
	CString str;
	m_editLeft.GetWindowText(str);
	m_iLeft = atoi(str.GetBuffer());
}

void CAtlasEditor2::OnEnChangeEditt()
{
	CString str;
	m_editTop.GetWindowText(str);
	m_iTop = atoi(str.GetBuffer());
}

void CAtlasEditor2::OnEnChangeEditw()
{
	CString str;
	m_editWidth.GetWindowText(str);
	m_iWidth = atoi(str.GetBuffer());
}

void CAtlasEditor2::OnEnChangeEdith()
{
	CString str;
	m_editHeight.GetWindowText(str);
	m_iHeight = atoi(str.GetBuffer());
}
