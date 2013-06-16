#include <Windows.h>
#include "..\\ProtocolDef.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const char* gc_config_file_name = ".\\data\\texinit";
const char* gc_base_dir = ".\\data\\image";

void process_single_file(const char* path, const WIN32_FIND_DATA& fd)
{
	cout << path << "\\" << fd.cFileName << endl;
}

void fill_textures(const char* path, vector<TextureProtocol>& vec)
{
	WIN32_FIND_DATA fd;
	string back_slash("\\");
	string all_file("*.*");
	string pw(path);
	string pws = pw + back_slash + all_file;
	HANDLE hFind = FindFirstFile(pws.c_str(), &fd);
	while(true)
	{
		if (fd.cFileName[0] != '.')
		{
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				string fnw(fd.cFileName);
				string new_path = pw + back_slash + fnw;
				fill_textures(new_path.c_str(), vec);
			}
			else
				process_single_file(path, fd);
		}
		if (!FindNextFile(hFind, &fd))
			break;
	}
}

void main()
{
	vector<TextureProtocol> vecTexture;
	fill_textures(gc_base_dir, vecTexture);
	/*ofstream ofs(gc_config_file_name);
	int c = vecTexture.size();
	ofs.write((char*)&c, sizeof(int));
	for(int i = 0; i < c; i++)
		ofs.write((char*)&(vecTexture[i]), sizeof(TextureProtocol));
	ofs.close();*/
	getchar();
}