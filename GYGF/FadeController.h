#ifndef __FADECONTROLLER_H__
#define __FADECONTROLLER_H__

#include "FrameBasedController.h"
class FadeController : public FrameBasedController
{
	unsigned m_curAlpha;
	bool m_fadeIn;

public:
	FadeController();
	virtual ~FadeController();
	virtual void Process();
	virtual void Control();
};

#endif