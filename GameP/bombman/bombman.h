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

}BOOM, *PBOOM;


void AsciiArt();
void Init(char maze[VERTICAL][HORIZON], PPLAYER player,PPOS startPos,PPOS endPos);
void Update(char maze[VERTICAL][HORIZON],PPLAYER player,vector<BOOM> vecBoom,vector<POS> boomEffect);
void Render(char maze[VERTICAL][HORIZON],PPLAYER player,vector<POS> boomEffect);

enum class MAPTYPE {
	WALL = '0', ROAD ='1', START ='2', END= '3'
};