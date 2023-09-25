#include "pch.h"
#include "Core.h"

bool Core::Init(HWND hWnd)
{
	this->_hWnd = hWnd;
	_hdc = GetDC(hWnd);
	return false;
}

void Core::Update()
{
	Rectangle(_hdc, 10, 10, 110, 110);
}
