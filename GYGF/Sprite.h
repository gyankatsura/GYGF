#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "RenderData.h"

class Layer;
class FrameBasedController;
class Sprite
{
public:
	Transform m_transform;
	unsigned char m_alpha;
protected:
	FrameBasedController* m_pController;
	Layer* m_pLayer;
	friend class Layer;
public:
	Sprite():m_pController(0), m_pLayer(0), m_alpha(0xff){}
	virtual ~Sprite();

	virtual void Process (){ProcessController();};
	virtual void Draw(){};
	void DetachController();
	
	void DetachAndDestroy();
	void SetController(FrameBasedController* c);
private:
	void ProcessController();
};

#endif