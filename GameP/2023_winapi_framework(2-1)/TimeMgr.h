#pragma once
#include "define.h"
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
public:
	const float& GetDT() { return m_dT; }
private:
	// DT(Delta time): 1프레임당 시간
	float m_dT;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llFrequency;

	// FPS(Frame per second): 1초당 몇 프레임
	UINT m_frameCount; // 지금 몇번 호출되었는지
	float m_accFrameTime; // 시간 누적(1초모으기용)
	UINT m_fps;	// 내가 원하는 FPS
};

