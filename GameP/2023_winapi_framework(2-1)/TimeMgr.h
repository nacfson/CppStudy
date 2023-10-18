#pragma once

#include "define.h"
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
private:
	// DT(Delta time) : 1프레임당 경과 시간

	//FPS(Frame Per Second) : 1초당 몇 프레임

	LARGE_INTEGER prevCount;
};

