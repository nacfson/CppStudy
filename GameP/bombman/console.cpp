#include "console.h"
#include <iostream>
using namespace std;
void FullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE)
		,CONSOLE_FULLSCREEN_MODE,0);

}

void Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x,y };
	SetConsoleCursorPosition(hOut,Cur);
}

void ConsoleCursor(bool value, DWORD dWord)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = value;
	curInfo.dwSize = dWord;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

void SetColor(COLOR color, COLOR backColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		((int)backColor << 4) | (int)color);
}
