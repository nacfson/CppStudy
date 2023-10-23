#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"


void TimeMgr::Init(){
	_prevCount = {};
	_curCount = {};
	_frequency = {};

	_frameCount = 0;
	_frameTime = 0.f;
	_fps = 0;

	//���� ���� �ð��� ī��Ʈ ���� �������ݴϴ�.
	QueryPerformanceCounter(&_prevCount);

	//1�ʴ� �� ī��Ʈ�� �Ǵ��� �˷��ݴϴ�.
	QueryPerformanceFrequency(&_frequency);
}

void TimeMgr::Update() {
	QueryPerformanceCounter(&_curCount);
	//DeltaTime
	_deltaTime = (float)(_curCount.QuadPart - _prevCount.QuadPart) / (float)_frequency.QuadPart;
	_prevCount = _curCount;

	//Fps�� ���غ���
	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.0f) {
		_fps = _frameCount / _frameTime;
		_frameTime = 0.f;
		_frameCount = 0;
		static wchar_t titleBuf[100] = {};
		swprintf_s(titleBuf, L"FPS: %d, DT: %f",_fps,_deltaTime);
		//wsprintf();
		SetWindowText(Core::GetInst()->GetHwnd(), titleBuf);
	}


}
