// AtlasMaker.h : AtlasMaker Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CAtlasMakerApp:
// �йش����ʵ�֣������ AtlasMaker.cpp
//

class CAtlasMakerApp : public CWinApp
{
public:
	CAtlasMakerApp();


// ��д
public:
	virtual BOOL InitInstance();
	void InitTexConfig();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAtlasMakerApp theApp;