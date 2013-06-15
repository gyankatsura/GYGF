#include "stdafx.h"
#include "d3dRender.h"

#define SAVE_RELEASE(x) if(x!=NULL) \
	{\
		x->Release();\
		x=NULL;\
	}

D3DRender::D3DRender()
:m_hRenderWnd(0)
,m_pD3D(0)
,m_pDevice(0)
,m_pSprite(0)
,m_eState(D3DS_UNINIT)
{
}

D3DRender::~D3DRender()
{
	Uninit();
}

bool D3DRender::Init(HWND hWnd)
{
	if (m_eState != D3DS_UNINIT)
		return false;

	m_pD3D = ::Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pD3D == NULL) return false;

	D3DPRESENT_PARAMETERS d3dpp;
	memset(&d3dpp, 0, sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferCount = 1;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = TRUE;
	HRESULT hr = m_pD3D->CreateDevice(0, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pDevice);
	if (FAILED(hr)) return false;

	hr = D3DXCreateSprite(m_pDevice, &m_pSprite);
	if (FAILED(hr)) return false;

	m_eState = D3DS_INIT;
	return true;
}

void D3DRender::Uninit()
{
	if (m_eState == D3DS_UNINIT) return;
	SAVE_RELEASE(m_pSprite)
	SAVE_RELEASE(m_pDevice)
	SAVE_RELEASE(m_pD3D)
}

IDirect3DTexture9* D3DRender::GetTexture(const char* filename)
{
	if (m_eState != D3DS_INIT) return NULL;
	string strFileName(filename);
	map<string, IDirect3DTexture9*>::iterator iter = m_mTexCache.find(strFileName);
	if (iter != m_mTexCache.end())
		return iter->second;
	else
	{
		IDirect3DTexture9* pNewTexture = NULL;
		D3DXCreateTextureFromFileA(m_pDevice, filename, &pNewTexture);
		if (pNewTexture == NULL) return NULL;
		m_mTexCache[strFileName] = pNewTexture;
		return pNewTexture;
	}
}