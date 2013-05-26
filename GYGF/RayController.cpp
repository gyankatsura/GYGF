#include "RayController.h"

void RayController::SetSprite(Sprite* pSprite)
{
	Controller::SetSprite(pSprite);
	m_start = pSprite->m_transform.translate;
}

void RayController::Control()
{
	if (m_pSprite == NULL) return;
	m_pSprite->m_transform.translate.x = m_start.x + m_speed.x * m_iFrameCounter;
	m_pSprite->m_transform.translate.y = m_start.y + m_speed.y * m_iFrameCounter;
}

void RayController::SetSpeed(float sx, float sy)
{
	m_speed.x = sx;
	m_speed.y = sy;
}