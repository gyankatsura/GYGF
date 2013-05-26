#ifndef __FRAMEANIMATIONMANAGER_H__
#define __FRAMEANIMATIONMANAGER_H__

#include "FrameAnimation.h"
#include <vector>
using namespace std;

class FrameAnimationManager
{
	static vector<FrameAnimation*>* sm_pVecAnimations;

public:
	static void Init();
	static bool AddAnimation(FrameAnimation* pAnimation);
	static FrameAnimation* GetAnimation(int id);
	static void Uninit();
	static void InitTest();
};

#endif