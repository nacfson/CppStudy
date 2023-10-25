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
//#include "Object.h"
class Core
{
	SINGLE(Core)
public:
	bool Init(HWND _hWnd, POINT _ptResolution);
	void GameLoop();
	void Release();
public:
	const HWND& GetHwnd() const { return m_hWnd; }
	const POINT& GetResolution() const { return m_ptResolution; }
private:
	void Update();
	void Render();
private:
	HWND	m_hWnd; // ���� ������ �ڵ�
	HDC		m_hDC;	 // ���� ������ DC
	// ������۸���
	HDC		m_hbackDC; // �� ���� DC
	HBITMAP m_hbackbit; // �� ���ۿ� ��Ʈ��

	POINT m_ptResolution;


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

