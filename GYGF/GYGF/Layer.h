#ifndef __LAYER_H__
#define __LAYER_H__

#include "D3DEnv.h"
#include "LayerAR.h"
#include "Sprite.h"
#include <vector>
using namespace std;

class Layer
{
public:
	LayerAR* m_pAfterRender1;
	LayerAR* m_pAfterRender2;

private:
	vector<Sprite*> m_vecSprites;
	vector<Sprite*> m_vecSpritesToRemove;
	void RemoveWaitingSprites();

public:
	Layer();
	~Layer();

	bool AddSprite(Sprite* sprite);
	bool RemoveSprite(Sprite* sprite);

	void Process();
	void BeginLayer();
	void DrawLayer();
	void EndLayer();
	void ClearAllSprites();
};

#endif