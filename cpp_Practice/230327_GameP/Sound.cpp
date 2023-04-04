#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include "resource.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

int main(void)
{ 
	//PlaySound(TEXT("laserShoot.wav"), NULL,SND_FILENAME);
	//PlaySound(TEXT("SystemDefault"), NULL, SND_ASYNC);
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	string sound[8] = {"도(1)","레(2)","미(3)" ,"파(4)" ,"솔(5)" ,"라(6)" ,"시(7)" ,"도(8)" };
	float soundValueArr[8] = { 523.25,587.33,659.26,698.46,783.99,880,987.77,1046.50 };

	srand((unsigned int)time(NULL));
	while (true)
	{
		system("cls");
		cout << "---------------------------------" << endl;
		cout << "l  절대 음감 게임  l";
		cout << "---------------------------------" << endl;

		cout << "설명 : 처음에 7음계를 들려 주고, " << endl;
		cout << "다음에 8개 중  한 개의 음을 들려 준다." << endl;
		cout << "그리고 그음을 번호를 맞힌다." << endl;
		cout << "---------------------------------" << endl;
		cout << "준비하고 아무 키나 누른다." << endl;
		char ch = _getch();

		for (int i = 0; i < 8; i++)
		{
			cout << sound[i];
			Beep(soundValueArr[i], 500);
			Sleep(250);
		}
		cout << endl;
		for (int i = 3; i > 0; i--)
		{
			
			cout  << "\r" << i << "...";
			system("cls");
			Sleep(250);
		}

		int randValue = rand() % 8;

		Beep(soundValueArr[randValue], 500);

		cout << "답을 맞춰주세요";
		int n;
		cin >> n;
		if (n == randValue)
		{
			cout << "잘하셨습니다";
		}
		else
		{
			cout << "틀렸습니다. 정답은" << sound[randValue] << "입니다.";
		}
		int end;
		cout << "게임을 끝내려면 0을 입력하세요" << endl;
		cin >> end; 
		if (end == 0)
			break;

	}
	

	return 0;
}