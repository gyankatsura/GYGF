#include <stdafx.h>
#include "CTextureConfig.h"

IMPLEMENT_SERIAL(CTextureConfig, CObject, 1)

CTextureConfig* CTextureConfig::sm_pInstance = NULL;
CTextureConfig* CTextureConfig::GetInstance()
{
	if (sm_pInstance == NULL)
		sm_pInstance = new CTextureConfig();
	return sm_pInstance;
}

void CTextureConfig::DelInstance()
{
	if (sm_pInstance != NULL)
	{
		delete sm_pInstance;
		sm_pInstance = NULL;
	}
}

CTextureConfig::CTextureConfig()
{}

CTextureConfig::~CTextureConfig()
{}

void CTextureConfig::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		
	}
	else
	{
		m_vecTextures.clear();
		int textureCount = 0;
		ar.Read(&textureCount, sizeof(int));
		for (int i = 0; i < textureCount; i++)
		{
			TextureProtocol tp;
			ar.Read(&tp, sizeof(tp));
			m_vecTextures.push_back(tp);
		}
	}
}