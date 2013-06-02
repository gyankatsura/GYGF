#include <fstream>
#include <iostream>
using namespace std;
#include "..\\ProtocolDef.h"

void main()
{
	ofstream os(".\\Data\\aniinit", ios::binary);
	//int i = 3;
	//os.write((char*)(&i), sizeof(int));
	//TextureProtocol tp;

	//memset(&tp, 0, sizeof(TextureProtocol));
	//tp.tex_id = 0;
	//strcpy(tp.path, "data\\image\\bg.jpg");
	//os.write((char*)(&tp), sizeof(TextureProtocol));

	//memset(&tp, 0, sizeof(TextureProtocol));
	//tp.tex_id = 1;
	//strcpy(tp.path, "data\\image\\mario.png");
	//os.write((char*)(&tp), sizeof(TextureProtocol));

	//memset(&tp, 0, sizeof(TextureProtocol));
	//tp.tex_id = 2;
	//strcpy(tp.path, "data\\image\\cloud.png");
	//os.write((char*)(&tp), sizeof(TextureProtocol));

	int aniCounter = 1;
	os.write((char*)&aniCounter, sizeof(int));


	int texId = 1;
	os.write((char*)&texId, sizeof(int));

	int fbc = 4;
	os.write((char*)&fbc, sizeof(int));
	FAFrameBlockProtocol fb;
	fb.rectId = 0;
	fb.frames = 1;
	os.write((char*)&fb, sizeof(FAFrameBlockProtocol));
	fb.rectId = 1;
	fb.frames = 1;
	os.write((char*)&fb, sizeof(FAFrameBlockProtocol));
	fb.rectId = 2;
	fb.frames = 1;
	os.write((char*)&fb, sizeof(FAFrameBlockProtocol));
	fb.rectId = 1;
	fb.frames = 1;
	os.write((char*)&fb, sizeof(FAFrameBlockProtocol));

	int obc = 4;
	os.write((char*)&obc, sizeof(int));
	FAOffsetBlockProtocol ob;
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 1;
	os.write((char*)&ob, sizeof(FAOffsetBlockProtocol));
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 1;
	os.write((char*)&ob, sizeof(FAOffsetBlockProtocol));
	ob.offsetX = 0;
	ob.offsetY = -1;
	ob.frames = 1;
	os.write((char*)&ob, sizeof(FAOffsetBlockProtocol));
	ob.offsetX = 0;
	ob.offsetY = 0;
	ob.frames = 1;
	os.write((char*)&ob, sizeof(FAOffsetBlockProtocol));

	int abc = 1;
	os.write((char*)&abc, sizeof(int));
	FAAlphaBlockProtocol ab;
	ab.alpha0 = 200;
	ab.alpha1 = 200;
	ab.frames = 4;
	os.write((char*)&ab, sizeof(FAAlphaBlockProtocol));

	os.close();
}