#ifndef __LAYERAR_H__
#define __LAYERAR_H__

#include "CommonData.h"
class LayerAR
{
protected:
	void SetRS();
public:
	virtual void AfterRender();
};

#endif