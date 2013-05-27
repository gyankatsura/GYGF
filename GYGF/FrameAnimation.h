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

struct OffsetBlock
{
	int offsetX;
	int offsetY;
	int frames;

	OffsetBlock(int ox = 0, int oy = 0, int f = 1)
		:offsetX(ox)
		,offsetY(oy)
		,frames(f)
	{}
};

struct AlphaBlock
{
	unsigned char alpha0;
	unsigned char alpha1;
	int frames;

	AlphaBlock(unsigned char a0 = 0xff, unsigned char a1 = 0xff, int f = 0)
		:alpha0(a0)
		,alpha1(a1)
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
	vector<OffsetBlock> m_vecFramesOffset;
	vector<AlphaBlock> m_vecFramesAlpha;
	WrapMode m_eWrapMode;
	int m_iTotalFrameNum;

public:
	FrameAnimation(int texId = 0);
	void Clear();
	void AddFrameBlock(const FrameBlock& fb);
	void AddFrameOffsetBlock(const OffsetBlock& ob);
	void AddFrameAlphaBlock(const AlphaBlock& ab);
	WrapMode GetWrapMode(){return m_eWrapMode;}
	int GetTotalFrameNum(){return m_iTotalFrameNum;}
	FrameBlock* GetFrameBlock(int frame);
	OffsetBlock* GetOffsetBlock(int frame);
	AlphaBlock* GetAlphaBlock(int frame, int* localFrame = NULL);
	int GetTexId(){return m_iTexId;}
};

#endif