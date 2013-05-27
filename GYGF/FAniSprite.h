#ifndef __FANISPRITE_H__
#define __FANISPRITE_H__

#include "Sprite.h"
#include "FrameAnimation.h"

enum AnimationState
{
	AS_PLAYING, //���ڲ���
	AS_STOP //��ͣ��
};

enum AnimationProcessType
{
	APT_LOCAL,	//�Լ�Process�����������ţ�����ĳЩЧ��������װ������߼���ϵ�޹صģ�
	APT_CONTROLLED //�Լ���Process����������õ�ǰ֡���������Ƕ����������������ϵ�ȽϽ��ģ�
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