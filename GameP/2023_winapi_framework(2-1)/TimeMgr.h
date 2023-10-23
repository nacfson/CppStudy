#pragma once

#include "define.h"
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
public:
	const float& GetDt() { return _deltaTime; }
private:
	// DT(Delta time) : 1�����Ӵ� ��� �ð�

	//FPS(Frame Per Second) : 1�ʴ� �� ������
	float _deltaTime;

	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _frequency;

	UINT _frameCount; //���� �� �� ȣ��Ǿ��°�
	float _frameTime; //�ð� ����(1�ʸ������)
	UINT _fps; //���� ���ϴ� fps
};

