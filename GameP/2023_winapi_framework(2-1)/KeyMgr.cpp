#include "pch.h"
#include "KeyMgr.h"
#include "Core.h"
void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY_TYPE::LAST; i++)
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	m_ptMouse = {};
}

void KeyMgr::Update()
{
	HWND hFocusWnd = GetFocus();
	if (hFocusWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; i++)
		{
			// 키가 눌렸따.
			if (GetAsyncKeyState(m_arrVKKey[i]))
			{
				// 이전에 눌렸어.
				if (m_vecKey[i].IsPrevCheck)
					m_vecKey[i].eState = KEY_STATE::PRESS;
				else
					m_vecKey[i].eState = KEY_STATE::DOWN;

				m_vecKey[i].IsPrevCheck = true;
			}
			// 키가 안눌렸다.
			else
			{
				// 이전에 눌렸어.
				if (m_vecKey[i].IsPrevCheck)
					m_vecKey[i].eState = KEY_STATE::UP;
				else
					m_vecKey[i].eState = KEY_STATE::NONE;
				m_vecKey[i].IsPrevCheck = false;
			}
		}
		GetCursorPos(&m_ptMouse);
		ScreenToClient(Core::GetInst()->GetHwnd(), &m_ptMouse);
	}
	else // 포커싱 해제 - alt + tap
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; i++)
		{
			m_vecKey[i].IsPrevCheck = false;
			if (m_vecKey[i].eState == KEY_STATE::PRESS ||
				m_vecKey[i].eState == KEY_STATE::DOWN)
				m_vecKey[i].eState = KEY_STATE::UP;
			if (m_vecKey[i].eState == KEY_STATE::UP)
				m_vecKey[i].eState = KEY_STATE::NONE;

		}
	}
	
}
