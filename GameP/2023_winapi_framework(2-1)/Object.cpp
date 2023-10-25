#include "pch.h"
#include "Object.h"

Object::Object()
	//: m_ptPos{}
	//, m_ptScale{}
{
}

Object::~Object()
{
}

void Object::Update()
{
	//Vec2 vPos = m_obj.GetPos();
	//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	//	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::LEFT) == KEY_STATE::UP)
	//if (KEY_UP(KEY_TYPE::LEFT))
	//	m_vPos.x -= 100.f * fDT;// *fDT; // DT
	//if (KEY_UP(KEY_TYPE::RIGHT))
	//	m_vPos.x += 100.f * fDT;
	//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	//	vPos.x += 100.f * fDT;
	//m_obj.SetPos(vPos);
}

void Object::Render(HDC _dc)
{
	//Vec2 vPos = m_obj.GetPos();
	//Vec2 vScale = m_obj.GetScale();
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
}
