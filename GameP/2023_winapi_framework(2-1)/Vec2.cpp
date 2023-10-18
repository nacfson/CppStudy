#include "pch.h"
#include "Vec2.h"

Vec2::Vec2()
{
}

Vec2::~Vec2()

{
}

Vec2::Vec2(float x, float y)
	:_x(x)
	, _y(y)
{
}

Vec2::Vec2(int x, int y)
	:_x((float)x)
	,_y((float)y)
{
}

Vec2::Vec2(POINT pt)
	:_x((float)pt.x)
	,_y((float)pt.y)
{
}

Vec2::Vec2(const Vec2& v)
	:_x(v._x)
	,_y(v._y)
{
}
