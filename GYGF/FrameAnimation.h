#ifndef __FRAME_ANIMATION_H__
#define __FRAME_ANIMATION_H__

#include <vector>
using namespace std;

struct FrameBlock
{
	int rectId;
	int frames;

	FrameBlock(int r = 0, int f = 1)
		:rectId(r)
		,frames(f)
	{}
};

enum WrapMode
{
	WRAPMODE_DEFAULT,
	WRAPMODE_LOOP
};

class FrameAnimation
{
	int m_iTexId;
	vector<FrameBlock> m_vecFrames;
	WrapMode m_eWrapMode;
	int m_iTotalFrameNum;

public:
	FrameAnimation(int texId = 0);
	void Clear();
	void AddFrameBlock(const FrameBlock& fb);
	WrapMode GetWrapMode(){return m_eWrapMode;}
	int GetTotalFrameNum(){return m_iTotalFrameNum;}
	FrameBlock* GetFrameBlock(int frame);
	int GetTexId(){return m_iTexId;}
};

#endif