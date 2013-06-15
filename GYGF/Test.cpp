#include "Test.h"
#include "Input.h"
#include "PlayerActor.h"

Sprite* g_sprite = NULL;
PlayerActor* pPlayer = NULL;

void TestInit()
{
	if (pPlayer == NULL) 
	{
		pPlayer = new PlayerActor();
		pPlayer->Embody();
	}
}

void TestProcess()
{
	if (pPlayer != NULL)
		pPlayer->Process();
}

void TestUninit()
{
	if (pPlayer != NULL)
		delete pPlayer;
}