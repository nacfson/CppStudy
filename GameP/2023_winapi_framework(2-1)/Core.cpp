#include "pch.h"
#include "Core.h"

bool Core::Init(HWND hWnd,POINT pResolution)
{
	this->_hWnd = hWnd;
	_hdc = GetDC(hWnd);
	_pResolution = pResolution;

	_obj.SetPos(Vec2({_pResolution.x/2,_pResolution.y/2}));
	_obj.SetScale(Vec2(100, 100));
	return true;
}

void Core::GameLoop()
{
	Update();
	Render();
}

void Core::Update()
{
	Vec2 pos = _obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		pos.x -= 0.01f;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		pos.x += -0.01f;
	_obj.SetPos(pos);
}

void Core::Render()
{
	Vec2 pos = _obj.GetPos();
	Vec2 scale = _obj.GetScale();

	RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _hdc);
}
