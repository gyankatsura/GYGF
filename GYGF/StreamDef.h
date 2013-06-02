#ifndef __STREAMDEF_H__
#define __STREAMDEF_H__

enum STREAM_SEEK_TYPE
{
	SST_SET,
	SST_CUR,
	SST_END
};

class Stream
{
public:
	virtual bool open(const char* path) = 0;
	virtual void seek(int offset, STREAM_SEEK_TYPE type) = 0;
	virtual int tell() = 0;
	virtual void close() = 0;
	virtual int size() = 0;
};

class ReadStream : public Stream
{
public:
	virtual int read(void* buf, int size) = 0;
};

class WriteStream : public Stream
{
public:
	virtual int write(void* buf, int size) = 0;
};

#endif