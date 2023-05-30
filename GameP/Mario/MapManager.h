#pragma once
#include "define.h"
class Stage; //Class 전방선언
class MapManager
{
private:
	MapManager();
	~MapManager();
private:
	static MapManager* m_pInst;
public:
	static MapManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
	static void DestroyInst() { SAFE_DELETE(m_pInst); }
private:
	Stage* map[3];
	int currentStage;
public :
	Stage* GetStage() {
		return map[currentStage];
	}
public:
	bool Init();
	void Run(int currentStage);
};