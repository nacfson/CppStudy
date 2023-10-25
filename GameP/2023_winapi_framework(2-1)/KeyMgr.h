#pragma once
#include "define.h"

struct tKeyInfo
{
	KEY_STATE eState;
	bool IsPrevCheck;
};

class KeyMgr
{
	SINGLE(KeyMgr);
private:
	vector<tKeyInfo> m_vecKey;
	int m_arrVKKey[(int)KEY_TYPE::LAST] =
	{ VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, 'Q' , 'W','E','R',
	'T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_CONTROL, VK_LMENU, VK_LSHIFT, VK_SPACE,
		VK_RETURN, VK_TAB, VK_ESCAPE, VK_LBUTTON, VK_RBUTTON };
	POINT m_ptMouse;
public:
	const POINT& GetMousepos() const { return m_ptMouse; }
	const KEY_STATE& GetKey(KEY_TYPE _eKey) const
	{
		return m_vecKey[(int)_eKey].eState;
	}
public:
	void Init();
	void Update();
};

