#ifndef __SPRITEBATCH_H__
#define __SPRITEBATCH_H__

#include "D3DEnv.h"
#include "CommonDef.h"

enum SpriteState
{
	NOT_READY,
	READY,
	BEGAN,
};

class SpriteBatch
{
	static SpriteState sm_state;
public:
	static bool Init();
	static void Begin();
	static void Draw(int tex_id, RectInt* rect, VecInt* pos, unsigned char alpha = 0xff, float scl = 1.0f, float rot = 0.0f);
	static void End();
	static void Uninit();
};

#endif