﻿#include<iostream>
#include<conio.h>
#include "StartScene.h"
#include "console.h"
using namespace std;
int GameMenu(){
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";
	while (true)
	{
		// iKey = 1: UP, 2: DOWN, 3: SPACE
		int iKey = KeyController();
			switch (iKey)
			{
			case (int)KEY::UP:
			{
				if (y > 12) // 13 ~ 14 일때만..
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
				if (y < 14) // 13 ~ 14 일때만..
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
				return y - 12;
			}
			break;
			}
		}

}

int KeyController() {
	// _getch() <==> _kbhit() , GetAsyncKeyState()
	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//	return (int)KEY::UP;
	//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//	return (int)KEY::DOWN;
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	return (int)KEY::SPACE;
	//	Sleep(200);
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
	system("cls");
	cout << endl << endl;
	cout << "[조작법]" << endl;
	cout << "메뉴 이동: 방향키" << endl;
	cout << "메뉴 선택: 스페이스바" << endl;
	cout << "방향키를 움직여 목표지점에 도착하세요." << endl;
	cout << "Spacebar: 폭탄설치, e: 푸시능력 ON/OFF" << endl;
	// 스페이스바를 눌러 나가고 싶어.
	while (true)
	{
		if (KeyController() == (int)KEY::SPACE)
			break;
	}
}
