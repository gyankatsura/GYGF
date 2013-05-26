#include "D3DEnv.h"
#include <d3dx9.h>
#include "Texture.h"
Texture::Texture():
m_pD3DTexture(NULL)
{
	
}

Texture::~Texture()
{
	Unload();
}

bool Texture::Load()
{
	if (m_sPath.empty()) return false;
	Unload();
	HRESULT hr = D3DXCreateTextureFromFileA(EnvGetDevice(), m_sPath.c_str(),
		&m_pD3DTexture);
	if (SUCCEEDED(hr))
	{
		D3DSURFACE_DESC desc;
		m_pD3DTexture->GetLevelDesc(0, &desc);
		m_iTextureWidth = desc.Width;
		m_iTextureHeight = desc.Height;
		return true;
	}
	return false;
}

void Texture::Unload()
{
	if (m_pD3DTexture != NULL)
	{
		m_pD3DTexture->Release();
		m_pD3DTexture = NULL;
	}
}

void Texture::SetPath(const string& path)
{
	m_sPath = path;
}

string Texture::GetPath()
{
	return m_sPath;
}

IDirect3DTexture9* Texture::GetD3DTexture()
{
	return m_pD3DTexture;
}

int Texture::GetWidth()
{
	return m_iTextureWidth;
}

int Texture::GetHeight()
{
	return m_iTextureHeight;
}