#include "D3DEnv.h"
#include <d3dx9.h>
#include "SpriteBatch.h"
#include "Texture.h"
#include "TextureManager.h"

ID3DXSprite* g_pSprite = 0;
SpriteState SpriteBatch::sm_state = NOT_READY;

bool SpriteBatch::Init()
{
	if (sm_state != NOT_READY) return false;
	if (EnvIsInited())
	{
		IDirect3DDevice9* pDevice = EnvGetDevice();
		HRESULT hr = D3DXCreateSprite(pDevice, &g_pSprite);
		if (SUCCEEDED(hr)) 
		{
			sm_state = READY;
			return true;
		}
	}
	return false;
}

void SpriteBatch::Begin()
{
	if (sm_state != READY) return;
	if (g_pSprite) g_pSprite->Begin(D3DXSPRITE_ALPHABLEND); else return;
	sm_state = BEGAN;
}

void SpriteBatch::Draw(int tex_id, RectInt* rect, VecInt* pos, float scl /* = 1.0f */, float rot /* = 0.0f */)
{
	if (sm_state != BEGAN) return;
	Texture* tex = TextureManager::GetTexture(tex_id);
	if (tex == NULL) return;
	
	RECT tex_rect;
	RECT* ptex_rect = &tex_rect;
	if (rect)
		SetRect(ptex_rect, rect->left, rect->top, rect->left + rect->width, rect->top + rect->height);
	else
		SetRect(ptex_rect, 0, 0, tex->GetWidth(), tex->GetHeight());
	D3DXVECTOR3 v3pos;
	v3pos.x = (pos == NULL) ? 0.0f : (float)(pos->x);
	v3pos.y = (pos == NULL) ? 0.0f : (float)(pos->y);
	v3pos.z = 0.0f;
	g_pSprite->Draw(tex->GetD3DTexture(), ptex_rect, NULL, &v3pos, 0xffffffff);
}

void SpriteBatch::End()
{
	if (sm_state != BEGAN) return;
	if (g_pSprite) g_pSprite->End();
	sm_state = READY;
}

void SpriteBatch::Uninit()
{
	if (sm_state != READY) return;
	if (g_pSprite)
	{
		g_pSprite->Release();
		g_pSprite = NULL;
	}
	sm_state = NOT_READY;
}