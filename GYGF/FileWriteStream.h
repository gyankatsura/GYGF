#ifndef __FILEWRITESTREAM_H__
#define __FILEWRITESTREAM_H__

#include "StreamDef.h"
#include <fstream>
using namespace std;

class FileWriteStream : public WriteStream
{
private:
	ofstream* m_pfileStream;
	int m_iSize;
public:
	FileWriteStream();
	~FileWriteStream();

	virtual bool open(const char* path);
	virtual void seek(int offset, STREAM_SEEK_TYPE type);
	virtual int tell();
	virtual void close();
	virtual int size();

	virtual int write(void* buf, int size);
};

#endif