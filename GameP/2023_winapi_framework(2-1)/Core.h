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

class Core
{
	SINGLE(Core)
public:
	bool Init(HWND hWnd);
	void Update();
private:
	HDC _hdc;
	HWND _hWnd;
	
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

