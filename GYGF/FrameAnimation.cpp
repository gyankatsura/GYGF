#include "FrameAnimation.h"

FrameAnimation::FrameAnimation(int texId)
:m_iTexId(texId)
,m_eWrapMode(WRAPMODE_LOOP)
,m_iTotalFrameNum(0)
{}

void FrameAnimation::Clear()
{
	int m_iTexId = 0;
	m_vecFrames.clear();
	m_iTotalFrameNum = 0;
}

void FrameAnimation::AddFrameBlock(const FrameBlock& fb)
{
	m_vecFrames.push_back(fb);
	m_iTotalFrameNum += fb.frames;
}

void FrameAnimation::AddFrameOffsetBlock(const OffsetBlock& ob)
{
	m_vecFramesOffset.push_back(ob);
}

void FrameAnimation::AddFrameAlphaBlock(const AlphaBlock& ab)
{
	m_vecFramesAlpha.push_back(ab);
}

FrameBlock* FrameAnimation::GetFrameBlock(int frame)
{
	if (frame < 0 || frame >= m_iTotalFrameNum) return NULL;
	for(int i = 0, m = m_vecFrames.size(); i < m; i++)
	{
		FrameBlock fb = m_vecFrames[i];
		if (frame <= fb.frames - 1)
			return &(m_vecFrames[i]);
		frame -= fb.frames;
	}
	return NULL;
}

OffsetBlock* FrameAnimation::GetOffsetBlock(int frame)
{
	if (frame < 0) return NULL;
	for(int i = 0, m = m_vecFramesOffset.size(); i < m; i++)
	{
		OffsetBlock ob = m_vecFramesOffset[i];
		if (frame <= ob.frames - 1)
			return &(m_vecFramesOffset[i]);
		frame -= ob.frames;
	}
	return NULL;
}

AlphaBlock* FrameAnimation::GetAlphaBlock(int frame, int* localFrame)
{
	if (frame < 0) return NULL;
	for(int i = 0, m = m_vecFramesAlpha.size(); i < m; i++)
	{
		AlphaBlock ab = m_vecFramesAlpha[i];
		if (frame <= ab.frames - 1)
		{
			if (localFrame != NULL) *localFrame = frame;
			return &(m_vecFramesAlpha[i]);
		}
		frame -= ab.frames;
	}
	return NULL;
}