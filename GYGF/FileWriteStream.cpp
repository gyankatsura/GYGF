#include "FileWriteStream.h"

FileWriteStream::FileWriteStream()
:m_pfileStream(0)
,m_iSize(-1)
{

}

FileWriteStream::~FileWriteStream()
{
	close();
}

bool FileWriteStream::open(const char* path)
{
	if (m_pfileStream != NULL) return false;
	m_pfileStream = new ofstream(path);
	if (m_pfileStream != NULL)
	{
		m_pfileStream->seekp(0, ios::end);
		m_iSize = m_pfileStream->tellp();
		m_pfileStream->seekp(0, ios::beg);
		return true;
	}
	return false;
}

void FileWriteStream::seek(int offset, STREAM_SEEK_TYPE type)
{
	if (m_pfileStream == NULL) return;
	if (type == SST_SET)
		m_pfileStream->seekp(offset, ios::beg);
	else if(type == SST_CUR)
		m_pfileStream->seekp(offset, ios::cur);
	else if(type == SST_END)
		m_pfileStream->seekp(offset, ios::end);
}

int FileWriteStream::size()
{
	return m_iSize;
}

int FileWriteStream::tell()
{
	if (m_pfileStream == NULL) return -1;
	return m_pfileStream->tellp();
}

void FileWriteStream::close()
{
	if (m_pfileStream != NULL)
	{
		m_pfileStream->close();
		delete m_pfileStream;
		m_pfileStream = NULL;
		m_iSize = -1;
	}
}

int FileWriteStream::write(void* buf, int size)
{
	if (m_pfileStream == NULL) return 0;
	m_pfileStream->write((char*)buf, size);
	return size;
}