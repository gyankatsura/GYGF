// AtlasMakerDoc.cpp : CAtlasMakerDoc 类的实现
//

#include "stdafx.h"
#include "AtlasMaker.h"

#include "AtlasMakerDoc.h"
#include "..\\ProtocolDef.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAtlasMakerDoc

IMPLEMENT_DYNCREATE(CAtlasMakerDoc, CDocument)

BEGIN_MESSAGE_MAP(CAtlasMakerDoc, CDocument)
END_MESSAGE_MAP()


// CAtlasMakerDoc 构造/析构

CAtlasMakerDoc::CAtlasMakerDoc()
{
	// TODO: 在此添加一次性构造代码

}

CAtlasMakerDoc::~CAtlasMakerDoc()
{
}

BOOL CAtlasMakerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CAtlasMakerDoc 序列化

void CAtlasMakerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int count = m_atlasList.size();
		ar.Write(&count, sizeof(int));
		for (int i = 0; i < count; i++)
		{
			AtlasProtocol ap = m_atlasList[i];
			ar.Write(&ap, sizeof(AtlasProtocol));
		}
	}
	else
	{
		m_atlasList.clear();
		int count = 0;
		ar.Read(&count, sizeof(int));
		AtlasProtocol dataBlock;
		for (int i = 0; i < count; i++)
		{
			ar.Read(&dataBlock, sizeof(AtlasProtocol));
			m_atlasList.push_back(dataBlock);
		}
	}
}


// CAtlasMakerDoc 诊断

#ifdef _DEBUG
void CAtlasMakerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAtlasMakerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAtlasMakerDoc 命令
