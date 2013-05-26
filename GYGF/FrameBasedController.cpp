#include "FrameBasedController.h"

FrameBasedController::FrameBasedController()
:m_iFrameCounter(0)
,m_iMaxFrameNum(0)
,m_eWrapMode(CWM_LOOP)
{
	
}

FrameBasedController::~FrameBasedController()
{
	
}

void FrameBasedController::Process()
{
	m_iFrameCounter++;
	if (m_iMaxFrameNum > 0 && m_iFrameCounter > m_iMaxFrameNum)
		OnEnd();
}

void FrameBasedController::OnEnd()
{
	switch (m_eWrapMode)
	{
	case CWM_LOOP:
		m_iFrameCounter = 0;
		break;
	case CWM_DESTROYSPRITE:
		if (m_pSprite != NULL) m_pSprite->DetachAndDestroy();
		break;
	case CWM_DETACH:
		if (m_pSprite != NULL) m_pSprite->DetachController();
		break;
	}
}