#ifndef __TIME_H__
#define __TIME_H__

#include <windows.h>

class Time
{
	static LARGE_INTEGER m_llStampStart;
	static LARGE_INTEGER m_llStampLast;
	static LARGE_INTEGER m_llStamp;
	static LARGE_INTEGER m_llFreq;

	static float m_fTime;
	static float m_fDeltaTime;
public:
	static void Start();
	static void SampleTime();
	static float GetDeltaTime(){return m_fDeltaTime;}
	static float GetTotalTime(){return m_fTime;}
};

#endif