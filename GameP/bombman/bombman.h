#pragma once
//#define HORIZON 20
//#define VERTICAL 20
#include <vector>

const int HORIZON = 21;
const int VERTICAL = 20;

//À§Ä¡
typedef struct _tagpos {
	int x;
	int y;
}POS, *PPOS;

//ÇÃ·¹ÀÌ¾î
typedef struct _tagplayer {
	POS pos;
	POS newPos;
	int bombPower;
	int bombCount;
	bool isGhost;
	bool isPush;
	bool isPushOnOff;
}PLAYER, *PPLAYER;

//ÆøÅº
typedef struct _tagboom {
	int x;
	int y;
	int life;
	bool die;
}BOOM, *PBOOM;


void AsciiArt();
void Init(char maze[VERTICAL][HORIZON], PPLAYER player,PPOS startPos,PPOS endPos);
void Update(char maze[VERTICAL][HORIZON],PPLAYER player,std::vector<BOOM>& vecBoom, std::vector<POS>& boomEffect);
void Render(char maze[VERTICAL][HORIZON],PPLAYER player, std::vector<POS>& boomEffect);
void BombCreate(PPLAYER player, char maze[VERTICAL][HORIZON], std::vector<BOOM>& vecBomb);
void Fire(char maze[VERTICAL][HORIZON],PPLAYER player, POS boomPos,std::vector<POS> boomEffect);
void Event(std::vector<BOOM>& _vecBoom);
bool GetItem(char item,PPLAYER player);               

enum class MAPTYPE {
	WALL = '0', ROAD = '1', START = '2', END = '3',	WATERBOMB = 'b', TWINKLE = 'p', POWER = '4', SLIME = '5', PUSH = '6',
};