#include "Atlas.h"

Atlas::Atlas(int texId, int bufferSize /* = 16 */)
{
	m_iTexId = texId;
	m_rectBuffer.Alloc(bufferSize);
	m_iRectNum = 0;
}

Atlas::~Atlas()
{
	
}

int Atlas::GetTexId()
{
	return m_iTexId;
}

void Atlas::AddRect(const RectInt& rect)
{
	if (m_iRectNum >= m_rectBuffer.GetSize())
		m_rectBuffer.Alloc(m_rectBuffer.GetSize() * 2);

	RectInt* pRect = m_rectBuffer.GetPointer() + m_iRectNum;
	*pRect = rect;
	m_iRectNum++;
}

RectInt* Atlas::GetRect(int index)
{
	if (index >= m_iRectNum || index < 0) return NULL;
	return (m_rectBuffer.GetPointer() + index);
}