#ifndef __COMMON_DATA_H__
#define __COMMON_DATA_H__

#include "D3DEnv.h"

template<class T>
class Buffer
{
	T* m_pPointer;
	int m_iSize;
public:
	Buffer():m_pPointer(0), m_iSize(0){};
	~Buffer(){Dealloc();}

	T* GetPointer(int index = 0){return m_pPointer + index;}
	int GetSize(){return m_iSize;}

	bool Alloc(int size){
		T* newBuffer = new T[size];
		if (newBuffer != NULL)
		{
			if (m_pPointer != NULL)
			{
				memcpy(newBuffer, m_pPointer, min(size, m_iSize));
				delete[] m_pPointer;
			}
			m_pPointer = newBuffer;
			m_iSize = size;
			return true;
		}
		return false;
	}
	void Dealloc(){
		if (m_pPointer != NULL)
		{
			delete[] m_pPointer;
			m_iSize = 0;
		}
	}
};

#endif