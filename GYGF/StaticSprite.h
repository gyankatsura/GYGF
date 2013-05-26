#ifndef __STATICSPRITE_H__
#define __STATICSPRITE_H__

#include "Sprite.h"

class StaticSprite : public Sprite
{
public:
	int m_iTexId;
	int m_iRectId;
public:
	StaticSprite();
	virtual void Draw();
};

#endif