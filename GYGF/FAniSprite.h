#ifndef __FANISPRITE_H__
#define __FANISPRITE_H__

#include "Sprite.h"
#include "FrameAnimation.h"

enum AnimationState
{
	AS_PLAYING, //正在播放
	AS_STOP //暂停中
};

enum AnimationProcessType
{
	APT_LOCAL,	//自己Process，不受外界干扰（比如某些效果，背景装饰物，与逻辑关系无关的）
	APT_CONTROLLED //自己不Process，由外界设置当前帧（比如主角动作，跟物理运算关系比较紧的）
};

class FAniSprite : public Sprite
{
	FrameAnimation* m_pAnimation;
	AnimationState m_eState;
	int m_iFrameSpeedDiv;
	int m_iFrameSpeedCounter;
	int m_iCurFrameNum;
	AnimationProcessType m_eProcessType;
public:
	FAniSprite();
	virtual ~FAniSprite();
	void SetAnimation(int ani_id, bool forceReset = true);
	void Restart();
	virtual void Process();
	virtual void Draw();
	virtual void Play();
	virtual void Pause();
	void SetCurFrame(int frame);
	void SetFrameSpeedDiv(int div){m_iFrameSpeedDiv = div;}
private:
	void ProcessFrame();
	void ProcessAnimationFrame();
};

#endif