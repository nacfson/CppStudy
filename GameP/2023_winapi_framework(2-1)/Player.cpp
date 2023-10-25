#include "pch.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_PRESS(KEY_TYPE::LEFT))
		vPos.x -= 100.f * fDT;// *fDT; // DT
	if (KEY_PRESS(KEY_TYPE::RIGHT))
		vPos.x += 100.f * fDT;
	SetPos(vPos);
}

//void Player::Render(HDC _dc)
//{
//}
