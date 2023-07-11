#include <iostream>
#include "GameLogic.h"
#include "StartScene.h"
#include <Windows.h>
#include "Console.h"
using namespace std;
int main(void) {
	char maze[VERTICAL][HORIZON] = {};
	POS startPos = {};
	PLAYER player = {};               
	KEY_CODE prevKeyCode = KEY_CODE::NONE;
	int oldDir; //그 전에 정해놨던 방향을 찾아야 함.
	Init(maze, &player, &startPos);
	                                                                 
	while (true) {
		AsciiArt();
		int menu = GameMenu();
		if (menu == 0) { //게임 시작
			break;
		}
		else if (menu == 1) { //게임 정보
			//게임의 정보를 띄운다, 스킵
		}
		else if (menu == 2) { //게임 종료
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++) {
				cout << "\r" << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
 		}
	}

	while (true) {
		Gotoxy(0, 0);

		Update(maze, &player, prevKeyCode);
		Render(maze, &player);
	}
	return 0;
}