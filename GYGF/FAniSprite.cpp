#include "FAniSprite.h"
#include "FrameAnimationManager.h"
#include "Windows.h"
#include "AtlasManager.h"
#include "SpriteBatch.h"
#include "FrameBasedController.h"

FAniSprite::FAniSprite()
: m_pAnimation(NULL)
, m_eState(AS_STOP)
, m_iFrameSpeedCounter(0)
, m_iFrameSpeedDiv(1)
, m_iCurFrameNum(0)
, m_eProcessType(APT_LOCAL)
{

}

FAniSprite::~FAniSprite()
{
	
}

void FAniSprite::SetAnimation(int ani_id, bool forceReset /* = true */)
{
	m_pAnimation = FrameAnimationManager::GetAnimation(ani_id);	
	if (m_pAnimation != NULL)
	{
		if (forceReset) Restart();
	}
	else
		OutputDebugString("Set Animation Fail -- FAniSprite");
}

void FAniSprite::Restart()
{
	m_eState = AS_PLAYING;
	m_iFrameSpeedCounter = 0;
	m_iCurFrameNum = 0;
}

void FAniSprite::Process()
{
	ProcessController();
	ProcessAnimationFrame();
}


void FAniSprite::ProcessFrame()
{
	if (m_pAnimation == NULL) return;
	int totalFrame = m_pAnimation->GetTotalFrameNum();
	m_iCurFrameNum++;
	if (m_iCurFrameNum >= totalFrame)
	{
		if (m_pAnimation->GetWrapMode() == WRAPMODE_DEFAULT)
		{
			m_iCurFrameNum = totalFrame - 1;
			m_eState = AS_STOP;
		}
		else if (m_pAnimation->GetWrapMode() == WRAPMODE_LOOP)
		{
			m_iCurFrameNum = 0;
		}
	}
}

void FAniSprite::Draw()
{
	if (m_pAnimation == NULL) return;
	FrameBlock* pBlock = m_pAnimation->GetFrameBlock(m_iCurFrameNum);
	if (pBlock != NULL)
	{
		int texId = m_pAnimation->GetTexId();
		Atlas* pAtlas = AtlasManager::GetAtlas(texId);
		if (pAtlas != NULL)
		{
			RectInt* pRect = pAtlas->GetRect(pBlock->rectId);
			if (pRect != NULL)
			{
				VecInt pos;
				pos.x = (int)(m_transform.translate.x);
				pos.y = (int)(m_transform.translate.y);
				SpriteBatch::Draw(texId, pRect, &pos);
			}
		}
	}
}

void FAniSprite::Play()
{
	m_eState = AS_PLAYING;
}

void FAniSprite::Pause()
{
	m_eState = AS_STOP;
}

void FAniSprite::SetCurFrame(int frame)
{
	if (m_pAnimation == NULL ||
		m_eProcessType != APT_CONTROLLED)
		return;
	m_iCurFrameNum = frame;
}

void FAniSprite::ProcessController()
{
	if (m_pController != NULL) m_pController->Process();//分开判断因为Process可能删掉Controller
	if (m_pController != NULL) m_pController->Control();
}

void FAniSprite::ProcessAnimationFrame()
{
	if (m_pAnimation == NULL || m_eState != AS_PLAYING || m_eProcessType != APT_LOCAL) return;
	m_iFrameSpeedCounter++;
	if (m_iFrameSpeedCounter >= m_iFrameSpeedDiv)
	{
		m_iFrameSpeedCounter -= m_iFrameSpeedDiv;
		ProcessFrame();
	}
}