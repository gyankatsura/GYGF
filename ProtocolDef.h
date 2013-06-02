#ifndef __PROTOCOLDEF_H__
#define __PROTOCOLDEF_H__

//Altasinit Protocol
struct AtlasProtocol
{
	int tex_id;
	int rect_left;
	int rect_top;
	int rect_width;
	int rect_height;
};

//Texture Initiating Protocol
struct TextureProtocol
{
	int tex_id;
	char path[260];
};

//Frame Animation -- Phase_1 : Frame Blocks
struct FAFrameBlockProtocol
{
	int rectId;
	int frames;
};

//Frame Animation -- Phase_2 : Offset Blocks
struct FAOffsetBlockProtocol
{
	int offsetX;
	int offsetY;
	int frames;
};

//Frame Animation -- Phase_3 : Alpha Blocks
struct FAAlphaBlockProtocol
{
	unsigned char alpha0;
	unsigned char alpha1;
	int frames;
};

#endif