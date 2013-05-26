#include "MeshDraw.h"
#include "D3DEnv.h"

void MeshDraw::Draw(Mesh* pMesh)
{
	IDirect3DDevice9* pDevice;
	pDevice = EnvGetDevice();
	if (pDevice != NULL)
		pDevice->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST,
			0, pMesh->vertices.GetSize(), pMesh->indices.GetSize() / 3,
			pMesh->indices.GetPointer(), D3DFMT_INDEX16, pMesh->vertices.GetPointer(),
			sizeof(VertexPDT));
}