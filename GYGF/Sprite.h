#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "RenderData.h"

class Layer;
class FrameBasedController;
class Sprite
{
public:
	Transform m_transform;
protected:
	FrameBasedController* m_pController;
	Layer* m_pLayer;
	friend class Layer;
public:
	Sprite():m_pController(0), m_pLayer(0){}
	virtual ~Sprite();

	virtual void Process (){};
	virtual void Draw(){};
	void DetachController();
	
	void DetachAndDestroy();
	void SetController(FrameBasedController* c);
};

#endif