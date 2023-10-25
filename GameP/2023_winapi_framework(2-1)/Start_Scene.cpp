#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"

void Start_Scene::Init()
{
	// ù ���� �� ������ ���
	// Object �߰�
	Object* pObj = new Player;
	pObj->SetScale(Vec2(100,100));
	pObj->SetPos(Vec2(600,300));
	AddObject(pObj, OBJECT_GROUP::PLAYER);
	

	Vec2 vResolution = Core::GetInst()->GetResolution();

	//몬스터 세팅
	Monster* pMonster = nullptr;
	int monsterCnt = 5;
	float fObjScale = 50.f;
	float fMoveDist = 10.f;
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale * 0.5f ) * 2)) / (monsterCnt-1);

	for (int i = 0; i < monsterCnt; ++i)
	{          
		pMonster = new Monster;
		pMonster->SetScale(Vec2(fObjScale, fObjScale));
		pMonster->SetPos(Vec2((fMoveDist+fObjScale * 0.5f) + (float)i * fTerm, 50.f));
		pMonster->SetCenterPos(pMonster->GetPos());
		pMonster->SetMaxDis(fMoveDist);
		AddObject(pMonster, OBJECT_GROUP::MONSTER);
	}

}

void Start_Scene::Update()
{
	this->Scene::Update();
	// �ʳװ� �˾Ƽ� ��..
	// ���������� Ŭ�����ϸ��� ������

}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}
