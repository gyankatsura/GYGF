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