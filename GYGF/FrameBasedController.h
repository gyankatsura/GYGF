#ifndef __FRAMEBASEDCONTROLLER_H__
#define __FRAMEBASEDCONTROLLER_H__

#include "Controller.h"

enum ControlWrapMode
{
	CWM_DETACH,
	CWM_LOOP,
	CWM_DESTROYSPRITE,
};

class FrameBasedController : public Controller
{
protected:
	int m_iFrameCounter;
	int m_iMaxFrameNum;
	ControlWrapMode m_eWrapMode;
	friend void Sprite::SetController(FrameBasedController* c);
	virtual void OnEnd();//当播放完成时调用，根据WrapMode处理结束事件
public:
	FrameBasedController();
	virtual ~FrameBasedController();
	virtual void Process();
	void SetWrapMode(ControlWrapMode mode){m_eWrapMode = mode;}
	void SetMaxFrame(int max){m_iMaxFrameNum = max;}
};

#endif