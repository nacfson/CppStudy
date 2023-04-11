#include "StartScene.h"
#include <iostream>
#include "console.h"
#include <conio.h>
using namespace std;

int GameMenu(){
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "게임시작";
	Gotoxy(x, y + 1);
	cout << "게임정보";
	Gotoxy(x, y + 2);
	cout << "게임 종료";

	while (1) {
		if (_kbhit()) {
			// UP = 1 ,DOWN = 2, SPACE = 3
			int iKey = KeyController();
			switch (iKey) {
			case (int)KEY::UP: {
				if (y > 12) {
					Gotoxy(x-2,y);
					cout << " ";
					Gotoxy(x-2,--y);
					cout << ">";
				}
				break;
			}
			case (int)KEY::DOWN:
				if (y > 14) {
					Gotoxy(x - 2, y);
					cout << " ";
					Gotoxy(x - 2, ++y);
					cout << ">";
				}
				break;
			case (int)KEY::SPACE:
				return y - 11;
				break;
			}
		}
	}
	return -1;
}

int KeyController()
{
	// cin, _getch() <==> _kbhit(), GetAsyncKeyState()
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return (int)KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return (int)KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		return (int)KEY::SPACE;
	}
	Sleep(200);
	return -1;
}

void GameInfo()
{
}
