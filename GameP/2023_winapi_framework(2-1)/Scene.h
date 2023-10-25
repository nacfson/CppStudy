#pragma once
//#include "Object.h" // �̰� ��ü�� ����Ҷ�
class Object;		// �����ͷ� ����Ҷ�
class Scene
{
public:
	Scene();
	virtual ~Scene();
public:
	// ���� ���� �Լ�
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

