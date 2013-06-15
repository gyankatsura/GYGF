#ifndef __PLAYERACTOR_H__
#define __PLAYERACTOR_H__

#include "Layer.h"
#include "Actor.h"

class PlayerActor : public Actor
{
public:
	static Layer* sm_pPlayerLayer;

	int x;
	int y;

	PlayerActor();
	~PlayerActor();
	void Process();
	virtual void Embody();
	virtual void Debody();
};

#endif