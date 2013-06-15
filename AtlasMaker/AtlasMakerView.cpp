// AtlasMakerView.cpp : CAtlasMakerView 类的实现
//

#include "stdafx.h"
#include "AtlasMaker.h"

#include "AtlasMakerDoc.h"
#include "AtlasMakerView.h"
#include "d3dRender.h"
#include "AtlasEditor2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAtlasMakerView

IMPLEMENT_DYNCREATE(CAtlasMakerView, CFormView)

BEGIN_MESSAGE_MAP(CAtlasMakerView, CFormView)
	ON_LBN_SELCHANGE(IDC_LIST2, &CAtlasMakerView::OnLbnSelchangeList2)
	ON_LBN_SELCHANGE(IDC_ATLAS, &CAtlasMakerView::OnLbnSelchangeAtlas)
	ON_LBN_DBLCLK(IDC_ATLAS, &CAtlasMakerView::OnLbnDblclkAtlas)
END_MESSAGE_MAP()

// CAtlasMakerView 构造/析构

CAtlasMakerView::CAtlasMakerView()
	: CFormView(CAtlasMakerView::IDD)
{
	// TODO: 在此处添加构造代码

}

CAtlasMakerView::~CAtlasMakerView()
{
}

void CAtlasMakerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listMain);
	DDX_Control(pDX, IDC_TEXPANEL, m_texPanel);
	DDX_Control(pDX, IDC_LIST1, m_listDebug);
	DDX_Control(pDX, IDC_ATLAS, m_listAtlas);
	DDX_Control(pDX, IDC_ATLASPANEL, m_atlasPanel);
}

BOOL CAtlasMakerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CAtlasMakerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CAtlasMakerDoc* pDoc = GetDocument();
	vector<TextureProtocol>::iterator iter = CTextureConfig::GetInstance()->m_vecTextures.begin();
	vector<TextureProtocol>::iterator iterEnd = CTextureConfig::GetInstance()->m_vecTextures.end();
	m_listMain.ResetContent();
	while(iter != iterEnd)
	{
		m_listMain.AddString(iter->path);
		iter++;
	}
	m_d3dTexPanelRender.Init(m_texPanel.m_hWnd);
	m_d3dAtlasPanelRender.Init(m_atlasPanel.m_hWnd);
}


// CAtlasMakerView 诊断

#ifdef _DEBUG
void CAtlasMakerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAtlasMakerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAtlasMakerDoc* CAtlasMakerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAtlasMakerDoc)));
	return (CAtlasMakerDoc*)m_pDocument;
}
#endif //_DEBUG
void CAtlasMakerView::OnLbnSelchangeList2()
{
	CString str;
	int curSel = m_listMain.GetCurSel();
	DrawTex(CTextureConfig::GetInstance()->m_vecTextures[curSel].path);
	m_strCurFileName = CTextureConfig::GetInstance()->m_vecTextures[curSel].path;
	RefreshAtlasList(curSel);
	m_iCurTexId = curSel;
}

void CAtlasMakerView::DrawTex(const char* filename)
{
	IDirect3DDevice9* pDevice = m_d3dTexPanelRender.GetDevice();
	if (pDevice == NULL) return;
	ID3DXSprite* pSprite = m_d3dTexPanelRender.GetSprite();
	if (pSprite == NULL) return;
	IDirect3DTexture9* pTexture = m_d3dTexPanelRender.GetTexture(filename);
	if (pTexture != NULL)
	{
		pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0xff112233, 1.0f, 0);
		pDevice->BeginScene();
		{
			pSprite->Begin(D3DXSPRITE_ALPHABLEND);
			{
				pSprite->Draw(pTexture, NULL, NULL, NULL, 0xffffffff);
			}
			pSprite->End();
		}
		pDevice->EndScene();
	}
	pDevice->Present(0, 0, 0, 0);
}

void CAtlasMakerView::DrawAtlas()
{
	IDirect3DDevice9* pDevice = m_d3dAtlasPanelRender.GetDevice();
	if (pDevice == NULL) return;
	ID3DXSprite* pSprite = m_d3dAtlasPanelRender.GetSprite();
	if (pSprite == NULL) return;
	IDirect3DTexture9* pTexture = m_d3dAtlasPanelRender.GetTexture(m_strCurFileName.c_str());
	if (pTexture != NULL)
	{
		pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0xff112233, 1.0f, 0);
		pDevice->BeginScene();
		{
			pSprite->Begin(D3DXSPRITE_ALPHABLEND);
			{
				AtlasProtocol db = (m_curAtlasList[m_iCurAtlasId]).data_block;
				RECT rect;
				::SetRect(&rect, db.rect_left, db.rect_top, db.rect_left + db.rect_width, db.rect_height + db.rect_top);
				pSprite->Draw(pTexture, &rect, NULL, NULL, 0xffffffff);
			}
			pSprite->End();
		}
		pDevice->EndScene();
	}
	pDevice->Present(0, 0, 0, 0);
}

void CAtlasMakerView::RefreshAtlasList(int tex_id)
{
	m_curAtlasList.clear();
	m_listAtlas.ResetContent();
	CAtlasMakerDoc* pDoc = GetDocument();
	if (pDoc == NULL) return;
	for (int i = 0, m = pDoc->m_atlasList.size(); i < m; ++i)
	{
		AtlasProtocol ap = pDoc->m_atlasList[i];
		if (ap.tex_id == tex_id)
		{
			AtlasRecord ar;
			ar.id_in_doc = i;
			ar.data_block = ap;
			m_curAtlasList.push_back(ar);
			CString str;
			str.Format("(%d,%d) %dx%d", 
				ap.rect_left,
				ap.rect_top,
				ap.rect_width,
				ap.rect_height);
			m_listAtlas.AddString(str);
		}
	}
}

void CAtlasMakerView::ShowAtlasEditor()
{
	m_dialogAtlasEditor.m_iLeft = (m_curAtlasList[m_iCurAtlasId]).data_block.rect_left;
	m_dialogAtlasEditor.m_iTop = (m_curAtlasList[m_iCurAtlasId]).data_block.rect_top;
	m_dialogAtlasEditor.m_iWidth = (m_curAtlasList[m_iCurAtlasId]).data_block.rect_width;
	m_dialogAtlasEditor.m_iHeight = (m_curAtlasList[m_iCurAtlasId]).data_block.rect_height;
	if (m_dialogAtlasEditor.DoModal() == IDOK)
	{
		AtlasProtocol ap;
		ap.tex_id = (m_curAtlasList[m_iCurAtlasId]).data_block.tex_id;
		ap.rect_left = m_dialogAtlasEditor.m_iLeft;
		ap.rect_top = m_dialogAtlasEditor.m_iTop;
		ap.rect_width = m_dialogAtlasEditor.m_iWidth;
		ap.rect_height = m_dialogAtlasEditor.m_iHeight;
		m_curAtlasList[m_iCurAtlasId].data_block = ap;
		CAtlasMakerDoc* pDoc = GetDocument();
		if (pDoc != NULL)
			pDoc->m_atlasList[m_curAtlasList[m_iCurAtlasId].id_in_doc] = ap;
	}
}

void CAtlasMakerView::OnLbnSelchangeAtlas()
{
	m_iCurAtlasId = m_listAtlas.GetCurSel();
	DrawAtlas();
}

void CAtlasMakerView::OnLbnDblclkAtlas()
{
	ShowAtlasEditor();
	RefreshAtlasList(m_iCurTexId);
	DrawAtlas();
}
