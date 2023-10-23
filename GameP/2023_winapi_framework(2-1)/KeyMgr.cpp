#include "pch.h"
#include "KeyMgr.h"
#include "Core.h"

void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY_TYPE::LAST; i++) {
		_vecKey.push_back(KeyInfo{ KEY_STATE::NONE,false });
	}
	_mouse = {};
}

void KeyMgr::Update(){
	HWND focusWnd = GetFocus();
	if (focusWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; i++) {
			if (GetAsyncKeyState(arrVKKey[i]))
			{
				if (_vecKey[i].isPrevCheck)
				{
					_vecKey[i].state = KEY_STATE::PRESS;
				}
				else
				{
					_vecKey[i].state = KEY_STATE::DOWN;
				}
				_vecKey[i].isPrevCheck = true;
			}

			else
			{
				if (_vecKey[i].isPrevCheck)
				{
					_vecKey[i].state = KEY_STATE::UP;
				}
				else
				{
					_vecKey[i].state = KEY_STATE::NONE;
				}
				_vecKey[i].isPrevCheck = true;
			}
		}

		GetCursorPos(&_mouse);
		ScreenToClient(Core::GetInst()->GetHwnd(), &_mouse);
	}
	else
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; i++) {
			_vecKey[i].isPrevCheck = false;
			if (_vecKey[i].state == KEY_STATE::PRESS || _vecKey[i].state == KEY_STATE::DOWN)
			{

			}
		}
	}
}

