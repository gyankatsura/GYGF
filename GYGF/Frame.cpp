#include "Game.h"
#include "Frame.h"

float Frame::sm_fTimeBuffer = 0.0f;

int Frame::GetFrameByTime(float time)
{
	sm_fTimeBuffer += time;
	int fr = GameGetFrameRate();
	int result = (int)(sm_fTimeBuffer * fr + 0.5f);
	sm_fTimeBuffer -= result * 1.0f / fr;
	return result;
}