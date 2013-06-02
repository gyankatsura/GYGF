#include "TextureManager.h"
#include "AtlasManager.h"
#include "FileReadStream.h"
#include "..\\ProtocolDef.h"

const char* AtlasManager::sm_initFileName = "data\\atlasinit";
vector<Atlas*>* AtlasManager::sm_pVecAtlas = NULL;

void AtlasManager::Init()
{
	sm_pVecAtlas = new vector<Atlas*>();
	int totalTexNum = TextureManager::GetTotalTextureNumber();
	sm_pVecAtlas->reserve(totalTexNum);
	for (int i = 0; i < totalTexNum; i++)
		sm_pVecAtlas->push_back(NULL);
	InitFromFile();
}

bool AtlasManager::AddAtlas(Atlas* atlas)
{
	if (atlas == NULL) return false;
	if ((*sm_pVecAtlas)[atlas->GetTexId()] == NULL)
		(*sm_pVecAtlas)[atlas->GetTexId()] = atlas;
	else return false;
	return true;
}

void AtlasManager::AddAtlas(int texId, const RectInt& rect)
{
	if ((*sm_pVecAtlas)[texId] == NULL)
		(*sm_pVecAtlas)[texId] = new Atlas(texId);
	(*sm_pVecAtlas)[texId]->AddRect(rect);
}

void AtlasManager::AddAtlas(int texId, int left, int top, int width, int height)
{
	RectInt ri;
	ri.left = left;
	ri.top = top;
	ri.width = width;
	ri.height = height;
	AddAtlas(texId, ri);
}

Atlas* AtlasManager::GetAtlas(int texId)
{
	if (texId < 0 || texId >= sm_pVecAtlas->size()) return NULL;
	return (*sm_pVecAtlas)[texId];
}

void AtlasManager::Uninit()
{
	for (int i = 0, m = sm_pVecAtlas->size(); i < m; ++i)
	{
		if ((*sm_pVecAtlas)[i] != 0)
		{
			delete (*sm_pVecAtlas)[i];
			(*sm_pVecAtlas)[i] = 0;
		}
	}
	if (sm_pVecAtlas != NULL) 
		delete sm_pVecAtlas;
}

void AtlasManager::InitTest()
{
	AddAtlas(0, 0, 0, 512, 512);
	AddAtlas(1, 0, 0, 14, 26);
	AddAtlas(1, 14, 0, 15, 26);
	AddAtlas(1, 29, 0, 15, 26);
	AddAtlas(2, 0, 0, 512, 512);
}

void AtlasManager::InitFromFile()
{
	FileReadStream frs;
	frs.open(sm_initFileName);
	int counter = 0;
	frs.read(&counter, sizeof(int));
	for (int i = 0; i < counter; i++)
	{
		AtlasProtocol ap;
		frs.read(&ap, sizeof(AtlasProtocol));
		AddAtlas(ap.tex_id, ap.rect_left, ap.rect_top, ap.rect_width, ap.rect_height);
	}
	frs.close();
}