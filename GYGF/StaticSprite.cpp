#include "AtlasManager.h"
#include "StaticSprite.h"
#include "TextureManager.h"
#include "SpriteBatch.h"

StaticSprite::StaticSprite()
:m_iTexId(0)
{

}

void StaticSprite::Draw()
{
	//Test
	if (m_iTexId == 1)
	{
		m_iRectId++;
		if (m_iRectId >= 16) m_iRectId -= 16;
	}
	//Test
	Texture* t = TextureManager::GetTexture(m_iTexId);
	VecInt vPos;
	vPos.x = (int)(m_transform.translate.x);
	vPos.y = (int)(m_transform.translate.y);
	Atlas* pAtlas = AtlasManager::GetAtlas(m_iTexId);
	if (pAtlas != NULL)
	{
		RectInt* pRect = pAtlas->GetRect(m_iRectId);
		if (pRect) SpriteBatch::Draw(m_iTexId, pRect, &vPos);
	}
}