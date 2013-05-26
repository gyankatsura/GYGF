#include "LayerAR.h"
#include "RenderData.h"
#include "MeshDraw.h"
#include <d3dx9.h>


ID3DXSprite* pSprite = NULL;

void LayerAR::AfterRender()
{
	GridMesh gm(1, 1);
	LPDIRECT3DTEXTURE9 pTexture = EnvGetExtraTexture();
	LPDIRECT3DDEVICE9 pDevice = EnvGetDevice();
	SetRS();
	pDevice->SetTexture(0, pTexture);
	MeshDraw::Draw(&gm);
	//SetRS();
	//if (pSprite == NULL)
	//{
	//	LPDIRECT3DDEVICE9 pDevice = EnvGetDevice();
	//	D3DXCreateSprite(pDevice, &pSprite);
	//}
	//pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	//pSprite->Draw(EnvGetExtraTexture(), 0, 0, 0, 0xffffffff);
	//pSprite->End();
}

void LayerAR::SetRS()
{
	LPDIRECT3DDEVICE9 pDevice = EnvGetDevice();
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA); 
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetFVF(MYFVF_PDT);
}