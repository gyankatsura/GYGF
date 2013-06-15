#include "Scene.h"
#include "SpriteBatch.h"
#include "D3DEnv.h"
#include "ARDistort.h"
#include "StaticSprite.h"
#include "FAniSprite.h"
#include "Test.h"
#include "RayController.h"
#include "PlayerActor.h"
#include "FadeController.h"

void Scene::MainRender()
{
	/*
	HRESULT hr = EnvGetDevice()->Clear(0, 0, D3DCLEAR_TARGET, 0xff443322, 1.0f, 0);
	EnvGetDevice()->BeginScene();
	SpriteBatch::Begin();
	SpriteBatch::Draw(0, NULL, NULL);
	SpriteBatch::End();
	EnvGetDevice()->EndScene();
	EnvGetDevice()->Present(NULL, NULL, NULL, NULL);
	*/
	IDirect3DDevice9* pDevice = EnvGetDevice();
	pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0xff443322, 1.0f, 0);
	pDevice->BeginScene();
	vector<Layer*>::iterator iter = m_vecLayers.begin();
	for (;iter != m_vecLayers.end();iter++)
	{
		(*iter)->BeginLayer();
		(*iter)->DrawLayer();
		(*iter)->EndLayer();
	}
	pDevice->EndScene();
	pDevice->Present(0, 0, 0, 0);
}

void Scene::MainLogic(float dt)
{

}

void Scene::MainProcess()
{
	TestProcess();
	vector<Layer*>::iterator iter = m_vecLayers.begin();
	for (; iter != m_vecLayers.end(); iter++)
		(*iter)->Process();
}

void Scene::Init()
{
	TestInit();
	::TestInit();
}

void Scene::TestInit()
{
	Layer* pLayer = new Layer;
	pLayer->m_pAfterRender2 = new ARDistort();
	pLayer->m_pAfterRender1 = new LayerAR();
	StaticSprite* ss = new StaticSprite();
	ss->m_iTexId = 0;
	ss->m_iRectId = 0;
	ss->m_transform.translate.x = 0.0f;
	ss->m_transform.translate.y = 0.0f;
	pLayer->AddSprite(ss);
	m_vecLayers.push_back(pLayer);

	

	/*pLayer = new Layer;
	pLayer->m_pAfterRender1 = new ARDistort();
	ss = new StaticSprite();
	ss->m_iTexId = 2;
	ss->m_iRectId = 0;
	ss->m_transform.translate.x = 0.0f;
	ss->m_transform.translate.y = 0.0f;
	pLayer->m_vecSprites.push_back(ss);
	m_vecLayers.push_back(pLayer);*/

	pLayer = new Layer;
	pLayer->m_pAfterRender1 = new LayerAR();
	for(int i = 0; i < 30; i++)
	{
		FAniSprite* fs = new FAniSprite();
		fs->SetAnimation(0);
		fs->m_transform.translate.x = rand() % 400;
		fs->m_transform.translate.y = rand() % 400;
		fs->SetFrameSpeedDiv(rand() % 5 + 5);
		pLayer->AddSprite(fs);
		//Test
		if (g_sprite == NULL) g_sprite = fs;
		//~Test
		//Test Controller
		//RayController* pc = new RayController();
		//pc->SetSpeed((rand() % 100 - 50) * 0.01f, (rand() % 100 - 50) * 0.01f);
		//pc->SetMaxFrame(rand() % 500 + 180);
		//pc->SetWrapMode(CWM_LOOP);
		//fs->SetController(pc);
		FadeController* fc = new FadeController();
		fc->SetWrapMode(CWM_LOOP);
		fs->SetController(fc);
		//~Test Controller
	}
	PlayerActor::sm_pPlayerLayer = pLayer;
	m_vecLayers.push_back(pLayer);
}

void Scene::Uninit()
{
	::TestUninit();
	vector<Layer*>::iterator iter = m_vecLayers.begin();
	for (;iter != m_vecLayers.end(); iter++)
		delete (*iter);
}