#pragma once
struct Vec2
{
public:
	Vec2();
	~Vec2();

	Vec2(float x, float y);
	Vec2(int x, int y);
	Vec2(POINT pt);
	Vec2(const Vec2& v);


public:
	float x;
	float y;
};

