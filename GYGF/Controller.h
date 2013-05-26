#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Sprite.h"

class Controller
{
protected:
	Sprite* m_pSprite;
	virtual void SetSprite(Sprite* pSprite);
public:
	Controller();
	virtual ~Controller();
	virtual void Control() = 0;
};

#endif