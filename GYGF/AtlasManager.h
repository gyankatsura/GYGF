#ifndef __ATLAS_MANAGER_H__
#define __ATLAS_MANAGER_H__

#include "Atlas.h"
#include <vector>
using namespace std;

class AtlasManager
{
	static vector<Atlas*>* sm_pVecAtlas;
public:
	static void Init();
	static void InitTest();
	static bool AddAtlas(Atlas* atlas);
	static void AddAtlas(int texId, const RectInt& rect);
	static void AddAtlas(int texId, int top, int left, int width, int height);
	static Atlas* GetAtlas(int texId);
	static void Uninit();
};

#endif