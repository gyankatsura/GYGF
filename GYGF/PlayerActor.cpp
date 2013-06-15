#include "PlayerActor.h"
#include "FAniSprite.h"
#include "Input.h"

Layer* PlayerActor::sm_pPlayerLayer = NULL;

PlayerActor::PlayerActor()
:x(0)
,y(0)
{

}

PlayerActor::~PlayerActor()
{
	Debody();
}


void PlayerActor::Process()
{
	if (Input::GetKey(0)) y -= 2;
	if (Input::GetKey(1)) y += 2;
	if (Input::GetKey(2)) x -= 2;
	if (Input::GetKey(3)) x += 2;
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

void PlayerActor::Debody()
{
	if (m_pSprite == NULL) return;
	m_pSprite->DetachAndDestroy();
	m_pSprite = NULL;
}