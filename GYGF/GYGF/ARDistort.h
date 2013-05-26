#ifndef __ARDISTORT_H__
#define __ARDISTORT_H__
#include "LayerAR.h"
class ARDistort: public LayerAR
{
public:
	virtual void AfterRender();
};

#endif