#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include <vector>
using namespace std;
#include "Layer.h"

class Scene
{
	string m_strName;
	vector<Layer*> m_vecLayers;
public:
	void Init();
	void TestInit();
	void MainLogic(float dt);
	void MainProcess();
	void MainRender();
	void Uninit();
	const string& GetName();
};

#endif