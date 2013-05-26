#ifndef __GAME_H__
#define __GAME_H__

#include <string>
using namespace std;

int GameInit(int width = 0, int height = 0, const char* title = 0);
void GameUninit();

int GameGetWidth();
int GameGetHeight();
const string& GameGetTitle();
int GameGetFrameRate();
void GameSetFrameRate(int fr);

void GameProcess(float dt);
void GameProcessByFrame();
void GameRender();

#endif