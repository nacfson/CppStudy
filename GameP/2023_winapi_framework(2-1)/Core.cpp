#include "pch.h"
#include "Core.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

bool Core::Init(HWND hWnd,POINT pResolution)
{
	this->_hWnd = hWnd;
	_backBit = 0;
	_backDC = 0;

	_pResolution = pResolution;


	//���� ���۸�
	_hDC = GetDC(hWnd);

	//1. ���� ������ ����
	_backBit = CreateCompatibleBitmap(_hDC,_pResolution.x,_pResolution.y);
	_backDC = CreateCompatibleDC(_hDC);
	//2. ����
	SelectObject(_backDC, _backBit);

	_obj.SetPos(Vec2({_pResolution.x/2,_pResolution.y/2}));
	_obj.SetScale(Vec2(100, 100));

	TimeMgr::GetInst()->Init();
	KeyMgr::GetInst()->Init();
	return true;
}

void Core::GameLoop()
{
	Update();
	Render();
}

void Core::Update()
{
	TimeMgr::GetInst()->Update();
	KeyMgr::GetInst()->Update();



	Vec2 pos = _obj.GetPos();
	if(KEY_UP(KEY_TYPE::LEFT))
		pos.x -= 100.0f * DELTATIME;
	if (KEY_UP(KEY_TYPE::RIGHT))
		pos.x += -100.0f * DELTATIME;
	
	_obj.SetPos(pos);
}


void Core::Render()
{
	//ȭ���� �����ϰ� ����� ����
	//Rectangle(_backDC, -1,-1,_pResolution.x + 1, _pResolution.y + 1);
	PatBlt(_backDC,0,0,_pResolution.x,_pResolution.y,WHITENESS);


	Vec2 pos = _obj.GetPos();
	Vec2 scale = _obj.GetScale();

	RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _hDC);

	POINT mousePos = KeyMgr::GetInst()->GetMousePos();


	//���� �����쿡 �Űܾ� �Ѵ�.
	//3. �ű��. -> Bitblt,stretchBlt,transblt,plgblt
	BitBlt(_hDC,0,0,_pResolution.x,_pResolution.y,_backDC,0,0,SRCCOPY); //SRCCOPY ��Ӻ���


}

void Core::Release()
{
	ReleaseDC(_hWnd, _hDC);
	DeleteDC(_backDC);
	DeleteObject(_backBit);



}
