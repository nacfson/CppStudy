#include "StartScene.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
using namespace std;

int GameMenu(){
    int result = 0;
	int x = 30, y = 7;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";
	Gotoxy(x - 2, y);
	cout << ">";

	while (true) {
		int key = KeyController();
		switch (key)
		{
		case (int)KEY::UP:
		{
			if (y > 7) // 13 ~ 14 일때만..
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
		}
		break;
		case (int)KEY::DOWN:
		{
			if (y < 9) // 13 ~ 14 일때만..
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}
		}
		break;
		case (int)KEY::SPACE:
		{
			return y - 7;
		}
		break;
		}
	}
    return result;
}

int KeyController(){
	int iKey = _getch();
	if (iKey == 224)
	{
		iKey = _getch();
		switch (iKey)
		{
		case 72: // UP
		{
			return (int)KEY::UP;
		}
		break;
		case 80: // DOWN
			return (int)KEY::DOWN;
			break;
		}
	}
	//enter 13
	else if (iKey == 32)
		system("cls");
	return (int)KEY::SPACE;
}

void GameInfo()
{
}
