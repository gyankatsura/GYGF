#ifndef __D3DRENDER_H__
#define __D3DRENDER_H__

#include <d3d9.h>
#include <d3dx9.h>
#include <map>
#include <string>
using namespace std;

enum D3DState
{
	D3DS_UNINIT,
	D3DS_INIT,
	D3DS_DEVICE_LOST
};

class D3DRender
{
	HWND m_hRenderWnd;
	IDirect3D9* m_pD3D;
	IDirect3DDevice9* m_pDevice;
	ID3DXSprite* m_pSprite;
	D3DState m_eState;
	map<string, IDirect3DTexture9*> m_mTexCache;
	
public:
	D3DRender();
	~D3DRender();
	ID3DXSprite* GetSprite(){return m_pSprite;}
	IDirect3DDevice9* GetDevice(){return m_pDevice;}
	IDirect3DTexture9* GetTexture(const char* filename);

	bool Init(HWND hWnd);
	void Uninit();
};
#endif