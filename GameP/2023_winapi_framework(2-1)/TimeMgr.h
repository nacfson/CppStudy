#pragma once

#include "define.h"
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
private:
	// DT(Delta time) : 1�����Ӵ� ��� �ð�

	//FPS(Frame Per Second) : 1�ʴ� �� ������

	LARGE_INTEGER prevCount;
};

