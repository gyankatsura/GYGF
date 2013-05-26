#ifndef __FRAME_H__
#define __FRAME_H__

class Frame
{
	static float sm_fTimeBuffer;
public:
	static int GetFrameByTime(float time);
};

#endif