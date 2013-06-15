// AtlasMakerDoc.cpp : CAtlasMakerDoc ���ʵ��
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


// CAtlasMakerDoc ����/����

CAtlasMakerDoc::CAtlasMakerDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CAtlasMakerDoc::~CAtlasMakerDoc()
{
}

BOOL CAtlasMakerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CAtlasMakerDoc ���л�

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


// CAtlasMakerDoc ���

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


// CAtlasMakerDoc ����
