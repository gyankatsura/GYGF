#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include "Texture.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class TextureManager
{
	static const char* sm_initFileName;
	static map<int, string>* sm_pIDPathMap;
	static vector<Texture*>* sm_pVecTextures;
	static int sm_iTotalTextureNum;
public:
	static void Init();
	static void InitFromFile();
	static Texture* GetTexture(int id);
	static void Clean();
	static int GetTotalTextureNumber();
};

#endif