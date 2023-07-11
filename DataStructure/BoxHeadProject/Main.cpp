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
	int oldDir; //�� ���� ���س��� ������ ã�ƾ� ��.
	Init(maze, &player, &startPos);
	                                                                 
	while (true) {
		AsciiArt();
		int menu = GameMenu();
		if (menu == 0) { //���� ����
			break;
		}
		else if (menu == 1) { //���� ����
			//������ ������ ����, ��ŵ
		}
		else if (menu == 2) { //���� ����
			cout << "������ �����մϴ�." << endl;
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