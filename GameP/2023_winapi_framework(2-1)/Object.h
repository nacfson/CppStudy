#pragma once
class Object
{
public :
	Object();
	virtual ~Object();
public:
	void SetPos(Vec2 pos) { ptPos = pos; }
public:
	void SetScale(Vec2 scale) { ptScale = scale; }
public:
	const Vec2& GetPos() const { return ptPos; }
public:
	const Vec2& GetScale() const { return ptScale; }
public :
	Vec2 ptPos;
	Vec2 ptScale;
};

