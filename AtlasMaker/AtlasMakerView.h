// AtlasMakerView.h : CAtlasMakerView ��Ľӿ�
//


#pragma once
#include "afxwin.h"
#include <vector>
#include "d3dRender.h"
#include "..\\ProtocolDef.h"
#include "AtlasEditor2.h"
using namespace std;

struct AtlasRecord
{
	int id_in_doc;
	AtlasProtocol data_block;
};

class CAtlasMakerView : public CFormView
{
protected: // �������л�����
	CAtlasMakerView();
	DECLARE_DYNCREATE(CAtlasMakerView)

public:
	enum{ IDD = IDD_ATLASMAKER_FORM };

// ����
public:
	vector<AtlasRecord> m_curAtlasList;
	CAtlasMakerDoc* GetDocument() const;
private:
	string m_strCurFileName;
	int m_iCurAtlasId;
	int m_iCurTexId;
	CAtlasEditor2 m_dialogAtlasEditor;

// ����
public:
	void DrawTex(const char* filename);
	void DrawAtlas();
	void RefreshAtlasList(int tex_id);
	void ShowAtlasEditor();
// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CAtlasMakerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listMain;
	CStatic m_texPanel;

//D3DRenders
private:
	D3DRender m_d3dTexPanelRender;
	D3DRender m_d3dAtlasPanelRender;
public:
	afx_msg void OnLbnSelchangeList2();
	CListBox m_listDebug;
	CListBox m_listAtlas;
	CStatic m_atlasPanel;
	afx_msg void OnLbnSelchangeAtlas();
	afx_msg void OnLbnDblclkAtlas();
};

#ifndef _DEBUG  // AtlasMakerView.cpp �еĵ��԰汾
inline CAtlasMakerDoc* CAtlasMakerView::GetDocument() const
   { return reinterpret_cast<CAtlasMakerDoc*>(m_pDocument); }
#endif

