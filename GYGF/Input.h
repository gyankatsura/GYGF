#ifndef __INPUT_H__
#define __INPUT_H__

#include <windows.h>

class Input
{
private:
	static int sm_iKeyNum;
	static unsigned char* sm_byteStateBuffer;
	static unsigned char* sm_byteStateBufferLast;
	static unsigned char* sm_byteKeyMap;
public:
	static void Init();
	static void UpdateInput();
	static bool GetKey(int id);
	static bool GetKeyDown(int id);
	static bool GetKeyUp(int id);
	static void Uninit();
};

#endif