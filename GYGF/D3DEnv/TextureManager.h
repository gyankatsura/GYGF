#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include "Texture.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class TextureManager
{
	static map<int, string>* sm_pIDPathMap;
	static vector<Texture*>* sm_pVecTextures;
	static const int TOTAL_TEXTURE_NUMBER;
public:
	static void Init();
	static Texture* GetTexture(int id);
	static void Clean();
	static int GetTotalTextureNumber();
};

#endif