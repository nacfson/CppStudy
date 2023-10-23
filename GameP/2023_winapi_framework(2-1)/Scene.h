#pragma once
#include "Object.h"
class Object;

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC dc);
	virtual void Release();
private:
	Object _obj;
	vector<Object*> _vecObjs[(UINT)OBJECT_GROUP::END];
};