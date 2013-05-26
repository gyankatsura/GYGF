#include "Game.h"
#include "Scene.h"
#include <string>
using namespace std;

int g_iWidth;
int g_iHeight;
string g_strTitle;
int g_iFrameRate = 60;

Scene* g_pCurrScene = NULL;
Scene* g_pNextScene = NULL;

int GameInit(int width /* = 0 */, int height /* = 0 */, const char* title /* = NULL */)
{
	g_iWidth = (width == 0) ? 640 : width;
	g_iHeight = (height == 0) ? 480 : height;
	g_strTitle = (title == 0) ? "<Title>" : title;
	g_pCurrScene = new Scene();
	g_pCurrScene->Init();
	return 0;
}

void GameUninit()
{
	if (g_pCurrScene != NULL)
	{
		g_pCurrScene->Uninit();
		delete g_pCurrScene;
		g_pCurrScene = NULL;
	}
	if (g_pNextScene != NULL)
	{
		g_pNextScene->Uninit();
		delete g_pNextScene;
		g_pNextScene = NULL;
	}
}

int GameGetWidth()
{
	return g_iWidth;
}

int GameGetHeight()
{
	return g_iHeight;
}

const string& GameGetTitle()
{
	return g_strTitle;
}

void GameProcess(float dt)
{//Test
	//char buf[256] = "";
	//sprintf(buf, "%d\n", (int)(dt * 1000000));
	//OutputDebugString(buf);
}

void GameProcessByFrame()
{
	if (g_pCurrScene != NULL) g_pCurrScene->MainProcess();
}

void GameRender()
{
	if (g_pCurrScene != NULL)
		g_pCurrScene->MainRender();
}

int GameGetFrameRate()
{
	return g_iFrameRate;
}

void GameSetFrameRate(int fr)
{
	g_iFrameRate = fr;
}