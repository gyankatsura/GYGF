// AtlasMakerView.h : CAtlasMakerView 类的接口
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
protected: // 仅从序列化创建
	CAtlasMakerView();
	DECLARE_DYNCREATE(CAtlasMakerView)

public:
	enum{ IDD = IDD_ATLASMAKER_FORM };

// 属性
public:
	vector<AtlasRecord> m_curAtlasList;
	CAtlasMakerDoc* GetDocument() const;
private:
	string m_strCurFileName;
	int m_iCurAtlasId;
	int m_iCurTexId;
	CAtlasEditor2 m_dialogAtlasEditor;

// 操作
public:
	void DrawTex(const char* filename);
	void DrawAtlas();
	void RefreshAtlasList(int tex_id);
	void ShowAtlasEditor();
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CAtlasMakerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // AtlasMakerView.cpp 中的调试版本
inline CAtlasMakerDoc* CAtlasMakerView::GetDocument() const
   { return reinterpret_cast<CAtlasMakerDoc*>(m_pDocument); }
#endif

