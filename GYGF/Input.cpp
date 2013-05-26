#include "Input.h"

int Input::sm_iKeyNum = 6;
unsigned char* Input::sm_byteStateBuffer = NULL;
unsigned char* Input::sm_byteStateBufferLast = NULL;
unsigned char* Input::sm_byteKeyMap = NULL;

void Input::Init()
{
	sm_byteStateBuffer = new unsigned char[sm_iKeyNum];
	memset(sm_byteStateBuffer, 0, sm_iKeyNum);
	sm_byteStateBufferLast = new unsigned char[sm_iKeyNum];
	memset(sm_byteStateBufferLast, 0, sm_iKeyNum);
	sm_byteKeyMap = new unsigned char[sm_iKeyNum];

	sm_byteKeyMap[0] = 'W';
	sm_byteKeyMap[1] = 'S';
	sm_byteKeyMap[2] = 'A';
	sm_byteKeyMap[3] = 'D';
	sm_byteKeyMap[4] = 'J';
	sm_byteKeyMap[5] = 'K';
}

void Input::UpdateInput()
{
	memcpy(sm_byteStateBufferLast, sm_byteStateBuffer, sm_iKeyNum);
	for (int i = 0; i < sm_iKeyNum; i++)
	{
		short state = GetKeyState(sm_byteKeyMap[i]);
		sm_byteStateBuffer[i] = (state & 0xff00) != 0x0000;
	}
}

bool Input::GetKey(int id)
{
	if (id < 0 || id >= sm_iKeyNum)
		return false;
	return sm_byteStateBuffer[id];
}

bool Input::GetKeyDown(int id)
{
	if (id < 0 || id >= sm_iKeyNum)
		return false;
	return sm_byteStateBuffer[id] && !sm_byteStateBufferLast[id];
}

bool Input::GetKeyUp(int id)
{
	if (id < 0 || id >= sm_iKeyNum)
		return false;
	return !sm_byteStateBuffer[id] && sm_byteStateBufferLast[id];
}

void Input::Uninit()
{
	if (sm_byteStateBuffer) {delete[] sm_byteStateBuffer;sm_byteStateBuffer = NULL;}
	if (sm_byteStateBufferLast) {delete[] sm_byteStateBufferLast;sm_byteStateBufferLast = NULL;}
	if (sm_byteKeyMap) {delete[] sm_byteKeyMap;sm_byteKeyMap = NULL;}
}