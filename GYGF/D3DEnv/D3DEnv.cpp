#include "D3DEnv.h"

HWND g_hWnd;
LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pDevice = NULL;
LPDIRECT3DTEXTURE9 g_pExtraTexture = NULL;
LPDIRECT3DSURFACE9 g_pMainSurfaceBackup = NULL;
bool g_bWindowClosed = false;
bool g_bInited = false;
bool g_bFocused = true;
bool g_bSizeMove = false;
void (*g_pfnExitSizeMoveCB)() = 0;

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
	case WM_CLOSE:
	case WM_QUIT:
		g_bWindowClosed = true;
		break;
	case WM_KILLFOCUS:
		g_bFocused = false;
		break;
	case WM_SETFOCUS:
		g_bFocused = true;
		break;
	case WM_ENTERSIZEMOVE:
		g_bSizeMove = true;
		break;
	case WM_EXITSIZEMOVE:
		g_bSizeMove = false;
		if (g_pfnExitSizeMoveCB) g_pfnExitSizeMoveCB();
		break;
	}

	return DefWindowProc( hWnd, msg, wParam, lParam );
}

bool EnvInit(int width, int height, const char* title)
{
	WNDCLASSEX wc;
	memset(&wc, 0, sizeof(WNDCLASSEX));
	//{
	//	sizeof(WNDCLASSEX), /*CS_CLASSDC*/ CS_OWNDC, MsgProc, 0L, 0L,
	//	GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
	//	title, NULL
	//};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = MsgProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = title;
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassEx( &wc );
	RECT desktopRect;
	HWND desktopHWND;
	desktopHWND = GetDesktopWindow();
	GetClientRect(desktopHWND, &desktopRect);
	RECT windowRect;
	SetRect(&windowRect, (desktopRect.right - width) / 2, (desktopRect.bottom - height) / 2,
						 (desktopRect.right + width) / 2, (desktopRect.bottom + height) / 2);
	BOOL ret = AdjustWindowRectEx(&windowRect, GYGF_GAMEWIN_STYLE, FALSE, GYGF_GAMEWIN_STYLE_EX);

	g_hWnd = CreateWindowEx(GYGF_GAMEWIN_STYLE_EX, title, title, 
		GYGF_GAMEWIN_STYLE, windowRect.left, windowRect.top, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top,
		NULL, NULL, wc.hInstance, NULL );

	if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		return false;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if( FAILED(g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pDevice )))
		return false;

	g_pDevice->CreateTexture(width, height, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &g_pExtraTexture, NULL);

	ShowWindow(g_hWnd, SW_SHOWNORMAL);
	UpdateWindow(g_hWnd);
	g_bWindowClosed = false;
	g_bInited = true;
	return true;
}

bool EnvIsInited()
{
	return g_bInited;
}

void EnvUninit()
{
	if (g_pDevice != NULL)
	{
		g_pDevice->Release();
		g_pDevice = NULL;
	}
	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
		g_pD3D = NULL;
	}
}

bool EnvHandleSysMessage()
{
	if (g_bWindowClosed) return false;
	MSG msg;
	if (PeekMessage(&msg, g_hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

HWND EnvGetHWND()
{
	return g_hWnd;
}

LPDIRECT3DDEVICE9 EnvGetDevice()
{
	return g_pDevice;
}

void EnvSwitchToExtra()
{
	g_pDevice->GetRenderTarget(0, &g_pMainSurfaceBackup);
	g_pMainSurfaceBackup->Release();
	LPDIRECT3DSURFACE9 pExtraSurface;
	g_pExtraTexture->GetSurfaceLevel(0, &pExtraSurface);
	g_pDevice->SetRenderTarget(0, pExtraSurface);
}

void EnvSwitchToMain()
{
	g_pDevice->SetRenderTarget(0, g_pMainSurfaceBackup);
}

void EnvSetExtraTexture()
{
	g_pDevice->SetTexture(0, g_pExtraTexture);
}

LPDIRECT3DTEXTURE9 EnvGetExtraTexture()
{
	return g_pExtraTexture;
}

bool EnvGetProcessEnable()
{
	return g_bFocused && !g_bSizeMove;
}

void EnvSetExitSizeMoveCB(void (*cb)())
{
	g_pfnExitSizeMoveCB = cb;
}