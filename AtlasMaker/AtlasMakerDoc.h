// AtlasMakerDoc.h : CAtlasMakerDoc ��Ľӿ�
//


#pragma once

#include "CTextureConfig.h"
#include <vector>
using namespace std;

class CAtlasMakerDoc : public CDocument
{
protected: // �������л�����
	CAtlasMakerDoc();
	DECLARE_DYNCREATE(CAtlasMakerDoc)

// ����
public:
	vector<AtlasProtocol> m_atlasList;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CAtlasMakerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


