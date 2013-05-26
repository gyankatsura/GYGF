#ifndef __ACTOR_H__
#define __ACTOR_H__

class Actor
{
protected:
	Sprite* m_pSprite;
public:
	virtual void Embody() = 0;
};

#endif