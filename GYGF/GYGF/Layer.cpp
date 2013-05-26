#include "Layer.h"
#include "D3DEnv.h"
#include "SpriteBatch.h"
#include <algorithm>

Layer::Layer():m_pAfterRender1(0),m_pAfterRender2(0)
{
	//m_pAfterRender = new LayerAR();
}

Layer::~Layer()
{
	if (m_pAfterRender1 != NULL) delete m_pAfterRender1;
	if (m_pAfterRender2 != NULL) delete m_pAfterRender2;
	ClearAllSprites();
}

bool Layer::AddSprite(Sprite* sprite)
{
	if (sprite == NULL) return false;
	m_vecSprites.push_back(sprite);
	sprite->m_pLayer = this;
	return true;
}

bool Layer::RemoveSprite(Sprite* sprite)
{
	m_vecSpritesToRemove.push_back(sprite);
	return true;
}

void Layer::RemoveWaitingSprites()
{
	vector<Sprite*>::iterator iter = m_vecSpritesToRemove.begin();
	for (;iter != m_vecSpritesToRemove.end(); iter++)
	{
		Sprite* pSprite = (*iter);
		vector<Sprite*>::iterator iterToErase = 
			std::find(m_vecSprites.begin(), m_vecSprites.end(), pSprite);
		if (iterToErase != m_vecSprites.end())
			m_vecSprites.erase(iterToErase);
		delete pSprite;
	}
	m_vecSpritesToRemove.clear();
}

void Layer::Process()
{
	RemoveWaitingSprites();
	vector<Sprite*>::iterator iter = m_vecSprites.begin();
	for (; iter != m_vecSprites.end(); iter++)
		(*iter)->Process();
}

void Layer::BeginLayer()
{
	EnvSwitchToExtra();
	EnvGetDevice()->Clear(0, 0, D3DCLEAR_TARGET, 0x00000000, 1.0f, 0);
	SpriteBatch::Begin();
}

void Layer::DrawLayer()
{
	//SpriteBatch::Draw(m_texid, NULL, NULL);
	vector<Sprite*>::iterator iter = m_vecSprites.begin();
	for (; iter != m_vecSprites.end(); iter++)
		(*iter)->Draw();
}

void Layer::EndLayer()
{
	SpriteBatch::End();
	EnvSwitchToMain();
	if (m_pAfterRender1) m_pAfterRender1->AfterRender();
	if (m_pAfterRender2) m_pAfterRender2->AfterRender();
}

void Layer::ClearAllSprites()
{
	vector<Sprite*>::iterator iter = m_vecSprites.begin();
	for (; iter != m_vecSprites.end(); iter++)
	{
		if (*iter != NULL)
		{
			delete (*iter);
			*iter = NULL;
		}
	}
	m_vecSprites.clear();
}