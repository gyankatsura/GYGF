/*
#include "CommonData.h"
#include "MathUtil.h"
using namespace math_util;

template<class T>
Buffer<T>::Buffer()
:m_pPointer(0)
,m_iSize(0)
{
	
}

template<class T>
Buffer<T>::~Buffer()
{
	if (m_pPointer != NULL)
		delete[] m_pPointer;
}

template<class T>
bool Buffer<T>::Alloc(int size)
{
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

template<class T>
void Buffer<T>::Dealloc()
{
	if (m_pPointer != NULL)
	{
		delete[] m_pPointer;
		m_iSize = 0;
	}
}*/