#ifndef __ATLAS_H__
#define __ATLAS_H__

#include "RenderData.h"
#include "CommonDef.h"
#include "CommonData.h"

class Atlas
{
	int m_iTexId;
	Buffer<RectInt> m_rectBuffer;
	int m_iRectNum;

public:
	Atlas(int texId, int bufferSize = 16);
	~Atlas();
	
	int GetTexId();
	void AddRect(const RectInt& rect);
	RectInt* GetRect(int index);
};

#endif