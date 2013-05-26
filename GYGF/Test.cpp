#include "Test.h"
#include "Input.h"
#include "PlayerActor.h"

Sprite* g_sprite = NULL;
PlayerActor* pPlayer = NULL;

void TestProcess()
{
	if (pPlayer == NULL) 
	{
		pPlayer = new PlayerActor();
		pPlayer->Embody();
	}
	pPlayer->Process();
}