#include "TextureManager.h"
#include "FileReadStream.h"
#include "..\\ProtocolDef.h"

const char* TextureManager::sm_initFileName = "data\\texinit";
map<int, string>* TextureManager::sm_pIDPathMap;
vector<Texture*>* TextureManager::sm_pVecTextures;
int TextureManager::sm_iTotalTextureNum = 3;

void TextureManager::Init()
{
	//TODO:
	sm_pIDPathMap = new map<int, string>();
	sm_pVecTextures = new vector<Texture*>();
	//(*sm_pIDPathMap)[0] = "data\\image\\bg.jpg";
	//(*sm_pIDPathMap)[1] = "data\\image\\mario.png";
	//(*sm_pIDPathMap)[2] = "data\\image\\cloud.png";
	InitFromFile();
	for (int i = 0; i < sm_iTotalTextureNum; i++)
		sm_pVecTextures->push_back(NULL);
}

void TextureManager::InitFromFile()
{
	ReadStream* rs = new FileReadStream();
	rs->open(sm_initFileName);

	rs->read(&sm_iTotalTextureNum, sizeof(int));
	for (int i = 0; i < sm_iTotalTextureNum; i++)
	{
		TextureProtocol tp;
		rs->read(&tp, sizeof(TextureProtocol));
		(*sm_pIDPathMap)[tp.tex_id] = tp.path;
	}

	rs->close();
	delete rs;
}

Texture* TextureManager::GetTexture(int id)
{
	if (id < 0 || id >= sm_pVecTextures->size()) return NULL;
	Texture* result_texture = (*sm_pVecTextures)[id];
	if (result_texture == NULL)
	{
		map<int, string>::iterator iter = sm_pIDPathMap->find(id);
		if (iter == sm_pIDPathMap->end()) return NULL;
		result_texture = new Texture();
		result_texture->SetPath(iter->second);
		if (result_texture->Load())
		{
			(*sm_pVecTextures)[id] = result_texture;
			return result_texture;
		}
		else
		{
			delete result_texture;
			return NULL;
		}
	}
	else
		return result_texture;
}

void TextureManager::Clean()
{
	if (sm_pVecTextures == NULL || sm_pIDPathMap == NULL) return;
	vector<Texture*>::iterator iter = sm_pVecTextures->begin();
	for (int i = 0, m = sm_pVecTextures->size(); i < m; i++)
	{
		if ((*sm_pVecTextures)[i] != NULL)
		{
			(*sm_pVecTextures)[i]->Unload();
			delete (*sm_pVecTextures)[i];
			(*sm_pVecTextures)[i] = NULL;
		}
	}
	delete sm_pVecTextures;
	delete sm_pIDPathMap;
}

int TextureManager::GetTotalTextureNumber()
{
	return sm_iTotalTextureNum;
}