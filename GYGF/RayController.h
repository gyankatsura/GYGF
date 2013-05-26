#ifndef __RAYCONTROLLER_H__
#define __RAYCONTROLLER_H__

#include "FrameBasedController.h"

class RayController : public FrameBasedController
{
	PointF m_speed;
	PointF m_start;

public:
	virtual void SetSprite(Sprite* pSprite);
	virtual void Control();

	void SetSpeed(float sx, float sy);
};

#endif