#pragma once
#define SINGLE(type)			\
private:						\
	type() {}					\
	~type() {}					\
public:							\
	static type* GetInst()		\
	{							\
		static type m_pInst;	\
		return &m_pInst;		\
	}

#define WINDOW_CLASS_NAME L"GAME_P"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define RECT_RENDER(posx, posy, scalex, scaley,hdc) Rectangle(hdc, posx - scalex/2, posy - scaley/2, posx + scalex/2, posy + scaley/2)
#define RECT_MAKE(posx, posy, scalex, scaley) { posx - scalex/2, posy - scaley/2, posx + scalex/2, posy + scaley/2 }
#define DELTATIME TimeMgr::GetInst()->GetDt();
#define KEY_CHECK(key,state) KeyMgr::GetInst()->GetKey(key) == state
#define KEY_NONE(key) KEY_CHECK(key,KEY_STATE::NONE)
#define KEY_DOWN(key) KEY_CHECK(key,KEY_STATE::DOWN)
#define KEY_UP(key) KEY_CHECK(key,KEY_STATE::UP)
#define KEY_PRESS(key) KEY_CHECK(key,KEY_STATE::PRESS)

enum class KEY_STATE
{
	NONE,DOWN,UP,PRESS
};

enum class KEY_TYPE
{
	LEFT,RIGHT,UP,DOWN,
	Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M
	,CTRL,LALT, LSHIFT,SPACE,ENTER,TAB,ESC,LMBTN,RMBTN,LAST

};