#ifndef __FILEREADSTREAM_H__
#define __FILEREADSTREAM_H__

#include "StreamDef.h"
#include <fstream>
using namespace std;

class FileReadStream : public ReadStream
{
private:
	ifstream* m_pfileStream;
	int m_iSize;
public:
	FileReadStream();
	~FileReadStream();

	virtual bool open(const char* path);
	virtual void seek(int offset, STREAM_SEEK_TYPE type);
	virtual int tell();
	virtual void close();
	virtual int size();

	virtual int read(void* buf, int size);
};

#endif