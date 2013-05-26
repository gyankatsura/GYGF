#include "RenderData.h"
#include "Game.h"

void GridMesh::GenBuffer()
{
	vertices.Dealloc();
	indices.Dealloc();

	vertices.Alloc((xGrids + 1) * (yGrids + 1));
	indices.Alloc(xGrids * yGrids * 6);

	for (int j = 0; j < yGrids + 1; j++)
	{
		for (int i = 0; i < xGrids + 1; i++)
		{
			int index = i + j * (xGrids + 1);
			VertexPDT* pVertex = vertices.GetPointer(index);
			pVertex->x = i * (2.0f / xGrids) - 1.0f + 1.0f / GameGetWidth();//half pixel offset;
			pVertex->y = - (j * (2.0f / yGrids) - 1.0f) - 1.0f / GameGetHeight();
			pVertex->z = 0.0f;
			pVertex->diffuse = 0xffffffff;
			pVertex->u = i * (1.0f / xGrids);
			pVertex->v = j * (1.0f / yGrids);
		}
	}

	for (unsigned short j = 0; j < yGrids; j++)
	{
		for (unsigned short i = 0; i < xGrids; i++)
		{
			int index = i + j * xGrids;
			unsigned short* pIndex;

			unsigned short vInd0 = i + j * (xGrids + 1);
			unsigned short vInd1 = vInd0 + 1;
			unsigned short vInd2 = vInd1 + (xGrids + 1);
			unsigned short vInd3 = vInd2 - 1;

			pIndex = indices.GetPointer(index * 6);
			*(pIndex + 0) = vInd0;
			*(pIndex + 1) = vInd1;
			*(pIndex + 2) = vInd2;
			*(pIndex + 3) = vInd0;
			*(pIndex + 4) = vInd2;
			*(pIndex + 5) = vInd3;
		}
	}
}