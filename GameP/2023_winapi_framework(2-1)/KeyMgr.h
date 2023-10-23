#pragma once
#include "define.h"
class KeyMgr
{
	SINGLE(KeyMgr);
private:
	vector<KeyInfo> _vecKey;
	int arrVKKey[(int)KEY_TYPE::LAST] =
	{ VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, 'Q' , 'W','E','R',
	'T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_CONTROL, VK_LMENU, VK_LSHIFT, VK_SPACE,
		VK_RETURN, VK_TAB, VK_ESCAPE, VK_LBUTTON, VK_RBUTTON };
	POINT _mouse;
public:
	void Init();
	void Update();
public :
	const POINT& GetMousePos() const { return _mouse; }
	const KEY_STATE& GetKey(KEY_TYPE key) const { return _vecKey[(int)key].state; }
};

struct KeyInfo
{
	KEY_STATE state;
	bool isPrevCheck;
};



