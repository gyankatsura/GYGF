#ifndef __D3DENV_H__
#define __D3DENV_H__

#include <windows.h>
#include <d3d9.h>

#define GYGF_GAMEWIN_STYLE WS_CAPTION|WS_POPUP|WS_VISIBLE|WS_CLIPSIBLINGS|WS_SYSMENU|WS_MINIMIZEBOX
#define GYGF_GAMEWIN_STYLE_EX WS_EX_LEFT|WS_EX_LTRREADING|WS_EX_RIGHTSCROLLBAR|WS_EX_WINDOWEDGE|WS_EX_APPWINDOW

bool EnvInit(int width, int height, const char* title);
bool EnvIsInited();
void EnvUninit();
bool EnvHandleSysMessage();
HWND EnvGetHWND();
LPDIRECT3DDEVICE9 EnvGetDevice();
void EnvSwitchToExtra();
void EnvSwitchToMain();
void EnvSetExtraTexture();
LPDIRECT3DTEXTURE9 EnvGetExtraTexture();
bool EnvGetProcessEnable();
void EnvSetExitSizeMoveCB(void (*cb)());

#endif