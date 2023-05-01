#include <iostream>
#include <vector> 
#include <Windows.h>
#include <mmsystem.h>
#include "bombman.h"
#include "StartScene.h"
#include "console.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

int main(void) {
	char maze[VERTICAL][HORIZON] = {};

	PLAYER player = {};
	POS startPos = {};
	POS endPos = {};
	vector<BOOM> vecBoom;
	vector<POS> boomEffect;

	Init(maze,&player,&startPos,&endPos);
	while (true) {
		AsciiArt();
		int iMenu = GameMenu();
		if(iMenu == 0) { //���� ����
			break;
		}
		else if (iMenu == 1) { //���� ����
			GameInfo();
		}
		else if (iMenu == 2) { //���� ����
			cout << "������ �����մϴ�" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "\r" << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}

	while (true) {
		Gotoxy(0, 0);
		Update(maze, &player,vecBoom,boomEffect );
		Render(maze, &player,boomEffect);

		if (player.pos.x == endPos.x && player.pos.y == endPos.y) {
			PlaySound(TEXT("random.wav"),0,SND_FILENAME | SND_ASYNC);
			Sleep(1000);
			break;
		}
	}

	return 0;
}