#include <iostream>
#include "console.h"
using namespace std;

int main(void)
{
	//FullScreen();
	//system("mode con cols=50 lines=50 | title �츶��");
	//SetConsoleTitle(TEXT("�츶��"));
	cout << "���";
	Gotoxy(10, 10);
	ConsoleCursor(false, 1);
	Sleep(2000);
	SetColor(COLOR::RED, COLOR::WHITE);
	cout << "���";
	//exit(0);
	//system("pause");
	int a = 0;
	cin >> a;

	//system("calc");
	//system("notepad");
	return 0;
}