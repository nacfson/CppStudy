#include "StartScene.h"
#include "Console.h"
#include <iostream>
using namespace std;

int GameMenu(){
    int result;
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";
    return result;
}

int KeyController(){
    int result;

    return result;
}

void GameInfo()
{
}
