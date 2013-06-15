#include "Sprite.h"

void TestInit();
void TestProcess();
void TestUninit();

extern Sprite* g_sprite;

//这个就是做测试用的，应该避免input直接操作sprite，
//应该又游戏逻辑的状态来控制