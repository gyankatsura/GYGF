#include "FrameAnimationManager.h"

vector<FrameAnimation*>* FrameAnimationManager::sm_pVecAnimations;

void FrameAnimationManager::Init()
{
	sm_pVecAnimations = new vector<FrameAnimation*>();
	sm_pVecAnimations->clear();
	InitTest();
}

bool FrameAnimationManager::AddAnimation(FrameAnimation* pAnimation)
{
	if (pAnimation == NULL) return false;
	sm_pVecAnimations->push_back(pAnimation);
	return true;
}

FrameAnimation* FrameAnimationManager::GetAnimation(int id)
{
	if (id >= sm_pVecAnimations->size() || id < 0) return NULL;
	return (*sm_pVecAnimations)[id];
}

void FrameAnimationManager::Uninit()
{
	if (sm_pVecAnimations == NULL) return;
	for (int i = 0, m = sm_pVecAnimations->size(); i < m; ++i)
	{
		if ((*sm_pVecAnimations)[i] != NULL)
		{
			delete (*sm_pVecAnimations)[i];
			(*sm_pVecAnimations)[i] = NULL;
		}
	}
	sm_pVecAnimations->clear();
	delete sm_pVecAnimations;
}

void FrameAnimationManager::InitTest()
{
	FrameAnimation* pAnimation = new FrameAnimation(1);
	FrameBlock fb;

	fb.rectId = 0;
	fb.frames = 1;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 1;
	fb.frames = 1;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 2;
	fb.frames = 1;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 1;
	fb.frames = 1;
	pAnimation->AddFrameBlock(fb);

	AddAnimation(pAnimation);
}