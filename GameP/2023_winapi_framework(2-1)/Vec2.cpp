#include "pch.h"
#include "Vec2.h"

Vec2::Vec2()
{
}

Vec2::~Vec2()

{
}

Vec2::Vec2(float x, float y)
	:x(x)
	, y(y)
{
}

Vec2::Vec2(int x, int y)
	:x((float)x)
	,y((float)y)
{
}

Vec2::Vec2(POINT pt)
	:x((float)pt.x)
	,y((float)pt.y)
{
}

Vec2::Vec2(const Vec2& v)
	:x(v.x)
	,y(v.y)
{
}
