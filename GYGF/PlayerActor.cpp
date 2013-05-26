#include "PlayerActor.h"
#include "FAniSprite.h"
#include "Input.h"

Layer* PlayerActor::sm_pPlayerLayer = NULL;

PlayerActor::PlayerActor()
:x(0)
,y(0)
{

}


void PlayerActor::Process()
{
	if (Input::GetKey(0)) y--;
	if (Input::GetKey(1)) y++;
	if (Input::GetKey(2)) x--;
	if (Input::GetKey(3)) x++;
	if (m_pSprite)
	{
		m_pSprite->m_transform.translate.x = x;
		m_pSprite->m_transform.translate.y = y;
	}
}

void PlayerActor::Embody()
{
	if (sm_pPlayerLayer == NULL) return;
	FAniSprite* pSprite = new FAniSprite();
	pSprite->SetAnimation(0);
	pSprite->SetFrameSpeedDiv(10);
	m_pSprite = pSprite;
	sm_pPlayerLayer->AddSprite(m_pSprite);
}