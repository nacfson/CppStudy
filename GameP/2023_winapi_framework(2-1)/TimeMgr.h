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
	// DT(Delta time) : 1프레임당 경과 시간

	//FPS(Frame Per Second) : 1초당 몇 프레임
	float _deltaTime;

	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _frequency;

	UINT _frameCount; //지금 몇 번 호출되었는가
	float _frameTime; //시간 누적(1초모으기용)
	UINT _fps; //내가 원하는 fps
};

