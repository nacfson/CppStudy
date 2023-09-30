#include "pch.h"
#include "Core.h"

bool Core::Init(HWND hWnd)
{
	this->_hWnd = hWnd;
	_hdc = GetDC(hWnd);
	_obj.ptPos = { 100,100 };
	_obj.ptScale = { 100,100 };
	return true;
}

void Core::GameLoop()
{
	Update();
	Render();
}

void Core::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		_obj.ptPos.x -= 1;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		_obj.ptPos.x += 1;
	}
}

void Core::Render()
{
	RECT_RENDER(_obj.ptPos.x, _obj.ptPos.y, _obj.ptScale.x, _obj.ptScale.y, _hdc);
}
