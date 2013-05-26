#ifndef __RENDERDATA_H__
#define __RENDERDATA_H__

#include "CommonData.h"

#define MYFVF_PDT (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct VertexPDT 
{
	float x;
	float y;
	float z;
	unsigned int diffuse;
	float u;
	float v;

	VertexPDT()
		:x(0.0f), y(0.0f), z(0.0f)
		,diffuse(0xffffffff)
		,u(0.0f), v(0.0f)
	{}
};

#define MYFVF_PDT2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct VertexPDT2D
{

	float x;
	float y;
	float z;
	float rhw;
	unsigned int diffuse;
	float u;
	float v;

	VertexPDT2D()
		:x(0.0f), y(0.0f), z(0.0f), rhw(1.0f)
		,diffuse(0xffffffff)
		,u(0.0f), v(0.0f)
	{}
};

struct PointF
{
	float x;
	float y;
	PointF():x(0.0f), y(0.0f){}
};

struct Transform
{
	PointF translate;
	PointF scaling;
	float rotation;

	Transform():rotation(0.0f)
	{
		scaling.x = 1.0f;
		scaling.y = 1.0f;
	}
};

typedef Buffer<VertexPDT> BufferVertex;
typedef Buffer<unsigned short> BufferIndex;

struct Mesh
{
	BufferVertex vertices;
	BufferIndex indices;
};

struct GridMesh : public Mesh
{
private:
	int xGrids;
	int yGrids;
	void GenBuffer();

public:
	GridMesh(int x, int y)
		:xGrids(x), yGrids(y)
	{GenBuffer();}
	~GridMesh(){};
};

#endif