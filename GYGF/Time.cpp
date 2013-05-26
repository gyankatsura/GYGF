#include "Time.h"

LARGE_INTEGER Time::m_llStampStart = {0};
LARGE_INTEGER Time::m_llStampLast = {0};
LARGE_INTEGER Time::m_llStamp = {0};
LARGE_INTEGER Time::m_llFreq = {0};

float Time::m_fTime = 0.0f;
float Time::m_fDeltaTime = 0.0f;

void Time::Start()
{
	QueryPerformanceFrequency(&m_llFreq);
	QueryPerformanceCounter(&m_llStampStart);
	m_llStampLast = m_llStamp = m_llStampStart;
}

void Time::SampleTime()
{
	m_llStampLast = m_llStamp;
	QueryPerformanceCounter(&m_llStamp);
	m_fTime = (m_llStamp.QuadPart - m_llStampStart.QuadPart) * 1.0f / m_llFreq.QuadPart;
	m_fDeltaTime = (m_llStamp.QuadPart - m_llStampLast.QuadPart) * 1.0f / m_llFreq.QuadPart;
}