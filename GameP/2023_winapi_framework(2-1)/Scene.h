#pragma once
//#include "Object.h" // 이거 자체를 써야할때
class Object;		// 포인터로 써야할때
class Scene
{
public:
	Scene();
	virtual ~Scene();
public:
	// 순수 가상 함수
	virtual void Init() abstract;
	virtual void Update();
	virtual void Render(HDC _dc);
	virtual void Release();
public:
	void AddObject(Object* _pObj, OBJECT_GROUP _eType)
	{
		m_vecobj[(UINT)_eType].push_back(_pObj);
	}
private:
//	Object* m_obj;
	vector<Object*> m_vecobj[(UINT)OBJECT_GROUP::END];
};

