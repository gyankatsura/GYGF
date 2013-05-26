#include "ARDistort.h"
#include "MeshDraw.h"
#include "RenderData.h"
#include "Input.h"
#include <cmath>
using namespace std;

void ARDistort::AfterRender()
{
	static float adding = 1.0f;
	static float revert = 0.0f;
	static bool add = true;
	//if (scale > 1.5f) scale = 1.0f;
	//if (Input::GetKey(0)) scale += 0.01f;
	adding += 0.01f;
	if (add) {revert += 0.01f;add = revert < 1.0f;}
	else {revert -= 0.01f;add = revert < 0.0f;}
	//if (revert > 1.5f) revert = 1.0f;
	static unsigned char alpha = 0xff;
	if (alpha > 0) alpha -= 0x05;
	else alpha = 0xff;
	GridMesh gm(100, 100);
	LPDIRECT3DTEXTURE9 pTexture = EnvGetExtraTexture();
	LPDIRECT3DDEVICE9 pDevice = EnvGetDevice();
	SetRS();
	for (int i = 0; i < gm.vertices.GetSize(); i++)
	{
		VertexPDT* pv = gm.vertices.GetPointer(i);
		float tf = pv->y;
		tf = tf * 10;
		tf = sinf(tf + adding * 10) * cos(adding);
		pv->x += tf;
		pv->y *= 1;
		pv->diffuse = 0x99 << 24;
		pv->diffuse += 0x00ffffff;
		int k = 0;
	}
	pDevice->SetTexture(0, pTexture);
	MeshDraw::Draw(&gm);
}