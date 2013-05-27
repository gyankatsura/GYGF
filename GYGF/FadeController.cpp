#include "FadeController.h"

FadeController::FadeController()
:m_curAlpha(0xff)
,m_fadeIn(false)
{

}

FadeController::~FadeController()
{
}

void FadeController::Process()
{
	if (m_fadeIn)
	{
		if (0xff - m_curAlpha < 0x02)
		{
			m_curAlpha = 0xff;
			m_fadeIn = false;
		}
		else m_curAlpha += 0x02;
	}
	else
	{
		if (m_curAlpha < 0x02)
		{
			m_curAlpha = 0x00;
			m_fadeIn = true;
		}
		else m_curAlpha -= 0x02;
	}
}

void FadeController::Control()
{
	if (m_pSprite)
		m_pSprite->m_alpha = m_curAlpha;
}
