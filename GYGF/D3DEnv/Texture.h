#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <d3d9.h>
#include <string>
using namespace std;

class Texture
{
	IDirect3DTexture9* m_pD3DTexture;
	int m_iTextureWidth;
	int m_iTextureHeight;
	string m_sPath;
public:
	Texture();
	~Texture();
	bool Load();
	void Unload();
	void SetPath(const string& path);
	string GetPath();
	IDirect3DTexture9* GetD3DTexture();
	int GetWidth();
	int GetHeight();
};

#endif