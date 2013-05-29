#include "FileReadStream.h"

FileReadStream::FileReadStream()
:m_pfileStream(0)
,m_iSize(-1)
{

}

FileReadStream::~FileReadStream()
{
	close();
}

bool FileReadStream::open(const char* path)
{
	if (m_pfileStream != NULL) return false;
	m_pfileStream = new ifstream(path);
	if (m_pfileStream != NULL) 
	{
		m_pfileStream->seekg(0, ios::end);
		m_iSize = m_pfileStream->tellg();
		m_pfileStream->seekg(0, ios::beg);
		return true;
	}
	return false;
}

void FileReadStream::seek(int offset, STREAM_SEEK_TYPE type)
{
	if (m_pfileStream == NULL) return;
	if (type == SST_SET)
		m_pfileStream->seekg(offset, ios::beg);
	else if(type == SST_CUR)
		m_pfileStream->seekg(offset, ios::cur);
	else if(type == SST_END)
		m_pfileStream->seekg(offset, ios::end);
}

int FileReadStream::size()
{
	return m_iSize;
}

int FileReadStream::tell()
{
	if (m_pfileStream == NULL) return -1;
	return m_pfileStream->tellg();
}

void FileReadStream::close()
{
	if (m_pfileStream != NULL)
	{
		m_pfileStream->close();
		delete m_pfileStream;
		m_pfileStream = NULL;
		m_iSize = -1;
	}
}

int FileReadStream::read(void* buf, int size)
{
	if (m_pfileStream == NULL) return 0;
	int curPos = m_pfileStream->tellg();
	size = size < (m_iSize - curPos) ? size : (m_iSize - curPos + 1);
	m_pfileStream->read((char*)buf, size);
	return size;
}