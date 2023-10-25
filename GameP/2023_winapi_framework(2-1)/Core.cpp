#include "pch.h"
#include "Core.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
bool Core::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd =_hWnd;
	m_hbackbit = 0;
	m_hbackDC = 0;
	m_ptResolution = _ptResolution;

	// 더블 버퍼링.
	m_hDC = GetDC(m_hWnd);
	// 1. 버퍼 공간을 생성
	m_hbackbit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_hbackDC = CreateCompatibleDC(m_hDC);
	// 2. 연결
	SelectObject(m_hbackDC, m_hbackbit);

	/*m_obj.SetPos(Vec2({ m_ptResolution.x / 2, m_ptResolution.y / 2 }));
	m_obj.SetScale(Vec2(100,100));*/

	// === Manager Init() ===
	TimeMgr::GetInst()->Init();
	KeyMgr::GetInst()->Init();
	SceneMgr::GetInst()->Init();
	return true;
}

void Core::Update()
{
	TimeMgr::GetInst()->Update();
	KeyMgr::GetInst()->Update();
	SceneMgr::GetInst()->Update();
//	Vec2 vPos = m_obj.GetPos();
////	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
////	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::LEFT) == KEY_STATE::UP)
//	if(KEY_UP(KEY_TYPE::LEFT))
//		vPos.x -= 100.f;// *fDT; // DT
//	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
//		vPos.x += 100.f * fDT;
//	m_obj.SetPos(vPos);
}

void Core::Render()
{
	// 화면을 깨끗하게 지우고 싶은거야.
	//Rectangle(m_hbackDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	PatBlt(m_hbackDC, 0,0, m_ptResolution.x, m_ptResolution.y, WHITENESS);
	SceneMgr::GetInst()->Render(m_hbackDC);

	//Vec2 vPos = m_obj.GetPos();
	//Vec2 vScale = m_obj.GetScale();
	//RECT_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, m_hbackDC);


	POINT mousepos = KeyMgr::GetInst()->GetMousepos();
	static wchar_t mousebuf[100] = {};
	swprintf_s(mousebuf, L"Mouse: x :%d, y :%d",mousepos.x, mousepos.y);
	TextOut(m_hbackDC, 10, 10, mousebuf, wcslen(mousebuf));
	// 우리 메인 윈도우에 옮겨야겠지?
	// 3. 옮긴다. -> bitblt, stretchblt, trans~, plgblt
	BitBlt(m_hDC, 0,0, m_ptResolution.x, m_ptResolution.y, m_hbackDC, 0,0, SRCCOPY);

	/*Rectangle(m_hDC
		, m_obj.m_ptPos.x - m_obj.m_ptScale.x /2
		, 10
		, 110
		, 110);*/
}

void Core::GameLoop()
{
	//static int count = 0;
	//++count;
	//static int prev = GetTickCount64();
	//int cur = GetTickCount64();
	//if (cur - prev > 1000)
	//{
	//	prev = cur;
	//	count = 0;
	//}
	Update();
	Render();
}

void Core::Release()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_hbackDC);
	DeleteObject(m_hbackbit);
}
