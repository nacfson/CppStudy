#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"
void TimeMgr::Init()
{
	m_llPrevCount = {};
	m_llCurCount = {};
	m_llFrequency = {};
	m_frameCount = 0;
	m_accFrameTime = 0.f;
	m_fps = 0;
	m_dT = 0.f;
	// 현재 지난 시간의 카운트 값을 가져와줍니다.
	QueryPerformanceCounter(&m_llPrevCount);
	// 1초당 몇카운트가 되는지 알려줍니다.
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// DT를 구했습니다.
	m_dT = (float)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (float)m_llFrequency.QuadPart;
	m_llPrevCount = m_llCurCount;

	// FPS를 구해보자. ???
	//	1. / m_dT;
	m_frameCount++; // 프레임 호출 누적
	m_accFrameTime += m_dT; // 시간 누적
	if (m_accFrameTime >= 1.f) // 1초
	{
		m_fps = m_frameCount / m_accFrameTime;
		m_accFrameTime = 0.f;
		m_frameCount = 0;
		static wchar_t titleBuf[100] = {};
		swprintf_s(titleBuf, L"FPS : %d, DT: %f",m_fps, m_dT);
//		wsprintf();
		SetWindowText(Core::GetInst()->GetHwnd(), titleBuf);

	}
}
