#pragma once
const int HORIZON = 50;
const int VERTICAL = 50;

typedef struct pos {
	int x;
	int y;
}POS, *PPOS;
typedef struct bullet {
	POS pos;
	int speed;
}BULLET, * PBULLET;

typedef struct gun {
	BULLET bullet;
}GUN, * PGUN;


typedef struct player {
	POS pos;
	GUN gun;

}PLAYER,*PPLAYER;


void Update(char maze[VERTICAL][HORIZON],PPLAYER player);
void Render(char maze[VERTICAL][HORIZON],PPLAYER player);
void Init(char maze[VERTICAL][HORIZON], PPOS startPos);
void Fire(PPOS startPos, PGUN gun);
void AsciiArt();

