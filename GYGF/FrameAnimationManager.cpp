#include "FrameAnimationManager.h"
#include "FileReadStream.h"
#include "..\\ProtocolDef.h"

const char* FrameAnimationManager::sm_initFileName = "data\\aniinit";
vector<FrameAnimation*>* FrameAnimationManager::sm_pVecAnimations;

void FrameAnimationManager::Init()
{
	sm_pVecAnimations = new vector<FrameAnimation*>();
	sm_pVecAnimations->clear();
	//InitTest();
	InitFromFile();
}

void FrameAnimationManager::InitFromFile()
{
	ReadStream* rs = new FileReadStream();
	rs->open(sm_initFileName);

	int anic;
	rs->read(&anic, sizeof(int));
	for (int i = 0; i < anic; i++)
	{
		int texId = 0;
		rs->read(&texId, sizeof(int));
		FrameAnimation* pAni = new FrameAnimation(texId);

		int fbc;
		rs->read(&fbc, sizeof(int));
		for (int j = 0; j < fbc; j++)
		{
			FAFrameBlockProtocol fb;
			rs->read(&fb, sizeof(FAFrameBlockProtocol));
			FrameBlock fbi;
			fbi.rectId = fb.rectId;
			fbi.frames = fb.frames;
			pAni->AddFrameBlock(fbi);
		}

		int obc;
		rs->read(&obc, sizeof(int));
		for (int j = 0; j < obc; j++)
		{
			FAOffsetBlockProtocol ob;
			rs->read(&ob, sizeof(FAOffsetBlockProtocol));
			OffsetBlock obi;
			obi.offsetX = ob.offsetX;
			obi.offsetY = ob.offsetY;
			obi.frames = ob.frames;
			pAni->AddFrameOffsetBlock(obi);
		}

		int abc;
		rs->read(&abc, sizeof(int));
		for (int j = 0; j < abc; j++)
		{
			FAAlphaBlockProtocol ab;
			rs->read(&ab, sizeof(FAAlphaBlockProtocol));
			AlphaBlock abi;
			abi.alpha0 = ab.alpha0;
			abi.alpha1 = ab.alpha1;
			abi.frames = ab.frames;
			pAni->AddFrameAlphaBlock(abi);
		}

		AddAnimation(pAni);
	}

	rs->close();
	delete rs;
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
	fb.frames = 5;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 1;
	fb.frames = 5;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 2;
	fb.frames = 5;
	pAnimation->AddFrameBlock(fb);
	fb.rectId = 1;
	fb.frames = 5;
	pAnimation->AddFrameBlock(fb);
	
	OffsetBlock ob;
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 5;
	pAnimation->AddFrameOffsetBlock(ob);
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 5;
	pAnimation->AddFrameOffsetBlock(ob);
	ob.offsetX = 0;
	ob.offsetY = -5;
	ob.frames = 5;
	pAnimation->AddFrameOffsetBlock(ob);
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 5;
	pAnimation->AddFrameOffsetBlock(ob);

	AlphaBlock ab;
	ab.alpha0 = 200;
	ab.alpha1 = 200;
	ab.frames = 20;
	pAnimation->AddFrameAlphaBlock(ab);

	AddAnimation(pAnimation);

}