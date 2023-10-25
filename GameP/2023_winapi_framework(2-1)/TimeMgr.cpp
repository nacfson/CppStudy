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
	// ���� ���� �ð��� ī��Ʈ ���� �������ݴϴ�.
	QueryPerformanceCounter(&m_llPrevCount);
	// 1�ʴ� ��ī��Ʈ�� �Ǵ��� �˷��ݴϴ�.
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// DT�� ���߽��ϴ�.
	m_dT = (float)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (float)m_llFrequency.QuadPart;
	m_llPrevCount = m_llCurCount;

	// FPS�� ���غ���. ???
	//	1. / m_dT;
	m_frameCount++; // ������ ȣ�� ����
	m_accFrameTime += m_dT; // �ð� ����
	if (m_accFrameTime >= 1.f) // 1��
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
