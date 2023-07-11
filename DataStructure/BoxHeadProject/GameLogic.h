#pragma once
const int HORIZON = 51;
const int VERTICAL = 20;

typedef struct pos {
	int x;
	int y;
}POS, *PPOS;
typedef struct bullet {
	POS pos;
	int speed;
	bool enabled;
}BULLET, * PBULLET;

typedef struct gun {
	BULLET bullet;
}GUN, * PGUN;

typedef struct player {
	POS pos;
	GUN gun;

}PLAYER,*PPLAYER;
enum class KEY_CODE {
	NONE, UP, DOWN, LEFT, RIGHT, SPACE
};


void Update(char maze[VERTICAL][HORIZON],PPLAYER player,KEY_CODE &keyCode);
void Render(char maze[VERTICAL][HORIZON],PPLAYER player);
void Init(char maze[VERTICAL][HORIZON],PPLAYER player, PPOS startPos);
void Fire(char maze[VERTICAL][HORIZON],POS startPos, GUN gun,KEY_CODE prevKeyCode);
void AsciiArt();

