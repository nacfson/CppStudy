#include "StartScene.h"
#include "Console.h"
#include <iostream>
using namespace std;

int GameMenu(){
    int result;
	int x = 30, y = 12;
	Gotoxy(x, y);
	cout << "���� ����";
	Gotoxy(x, y + 1);
	cout << "���� ����";
	Gotoxy(x, y + 2);
	cout << "���� �ϱ�";
    return result;
}

int KeyController(){
    int result;

    return result;
}

void GameInfo()
{
}
