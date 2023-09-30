#pragma once
/* 싱글톤: 단 하나의 객체만 메모리에 상주하고, 어디서든 참조할 수 있어야 한다.
*  1. 다이나믹 싱글톤 => 동적 할당
*  장점: 만드는 순서를 지정할 수 있따. / 단점: 불러지지않으면 객체초기화x,  꼭 지워줘야해.
* 2. 정적 싱글톤
* 
*/
//private:
//	static Core* m_pInst;
//public:
//	static Core* GetInst()
//	{
//		if (m_pInst == nullptr)
//			m_pInst = new Core;
//		return m_pInst;
//	}
//public:
//	static void DestroyInst()
//	{
//		SAFE_DELETE(m_pInst);
#include "define.h"
#include "pch.h"
#include "Object.h"

class Core
{
	SINGLE(Core)
public:
	bool Init(HWND hWnd);
	void GameLoop();
private:
	void Update();
	void Render();
private:
	HDC _hdc;
	HWND _hWnd;
	Object _obj;
//private:
//	Core();
//	~Core();
//public:
//	static Core* GetInst()
//	{
//		static Core m_pInst;
//		return &m_pInst;
//	}
};

