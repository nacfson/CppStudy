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
	// DT(Delta time): 1�����Ӵ� �ð�
	float m_dT;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llFrequency;

	// FPS(Frame per second): 1�ʴ� �� ������
	UINT m_frameCount; // ���� ��� ȣ��Ǿ�����
	float m_accFrameTime; // �ð� ����(1�ʸ������)
	UINT m_fps;	// ���� ���ϴ� FPS
};

