// AtlasMakerDoc.h : CAtlasMakerDoc 类的接口
//


#pragma once

#include "CTextureConfig.h"
#include <vector>
using namespace std;

class CAtlasMakerDoc : public CDocument
{
protected: // 仅从序列化创建
	CAtlasMakerDoc();
	DECLARE_DYNCREATE(CAtlasMakerDoc)

// 属性
public:
	vector<AtlasProtocol> m_atlasList;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CAtlasMakerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


