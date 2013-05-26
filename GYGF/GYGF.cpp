#include "Game.h"
#include "TextureManager.h"
#include "AtlasManager.h"
#include "D3DEnv.h"
#include "SpriteBatch.h"
#include "Time.h"
#include "Input.h"
#include "Frame.h"
#include "FrameAnimationManager.h"
#include <Windows.h>
#include <crtdbg.h>

void OnExitSizeMove()
{
	Time::SampleTime();
}

INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(196);
	FrameAnimationManager::Init();
	GameInit(512,512);
	if (!EnvInit(GameGetWidth(), GameGetHeight(), GameGetTitle().c_str()))
	{
		MessageBox(NULL, "Init Failed", "Error", MB_OK);
		return 1;
	}
	TextureManager::Init();
	AtlasManager::Init();
	SpriteBatch::Init();
	Time::Start();
	Input::Init();
	EnvSetExitSizeMoveCB(OnExitSizeMove);
	while (EnvHandleSysMessage())
	{
		Time::SampleTime();
		Input::UpdateInput();
		if (!EnvGetProcessEnable()) continue;
		float dt = Time::GetDeltaTime();
		GameProcess(dt);
		int frames = Frame::GetFrameByTime(dt);
		char buf[100] = "";
		sprintf(buf, "frames = %d\n", frames);
		OutputDebugString(buf);
		for(int i = 0; i < frames; ++i)
			GameProcessByFrame();
		GameRender();
	}
	FrameAnimationManager::Uninit();
	Input::Uninit();
	AtlasManager::Uninit();
	TextureManager::Clean();
	SpriteBatch::Uninit();
	EnvUninit();
	GameUninit();
	//_CrtDumpMemoryLeaks();
    return 0;
}



