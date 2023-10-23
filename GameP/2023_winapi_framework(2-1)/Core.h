#pragma once
/* �̱���: �� �ϳ��� ��ü�� �޸𸮿� �����ϰ�, ��𼭵� ������ �� �־�� �Ѵ�.
*  1. ���̳��� �̱��� => ���� �Ҵ�
*  ����: ����� ������ ������ �� �ֵ�. / ����: �ҷ����������� ��ü�ʱ�ȭx,  �� ���������.
* 2. ���� �̱���
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
	bool Init(HWND hWnd,POINT pResolution);
	void GameLoop();
	const HWND& GetHwnd() const { return _hWnd; }
private:
	void Update();
	void Render();
public:
	void Release();
private:
	HWND _hWnd; //���� ������ �ڵ�
	HDC _hDC;  //���� ������ DC
	HDC _backDC;  //�� ���� DC
	HBITMAP _backBit; //�� ���ۿ� ��Ʈ��



	POINT _pResolution;
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

