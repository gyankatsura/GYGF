#ifndef __CTEXTURECONFIG_H__
#define __CTEXTURECONFIG_H__

#include "..\\ProtocolDef.h"
#include <vector>
using namespace std;

class CTextureConfig : public CObject
{
	DECLARE_SERIAL(CTextureConfig)
private:
	static CTextureConfig* sm_pInstance;
	CTextureConfig();
	~CTextureConfig();

public:
	static CTextureConfig* GetInstance();
	static void DelInstance();
	std::vector<TextureProtocol> m_vecTextures;
	void Serialize(CArchive& ar);
};

#endif