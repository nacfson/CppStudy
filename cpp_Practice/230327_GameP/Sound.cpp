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
	string sound[8] = {"��(1)","��(2)","��(3)" ,"��(4)" ,"��(5)" ,"��(6)" ,"��(7)" ,"��(8)" };
	float soundValueArr[8] = { 523.25,587.33,659.26,698.46,783.99,880,987.77,1046.50 };

	srand((unsigned int)time(NULL));
	while (true)
	{
		system("cls");
		cout << "---------------------------------" << endl;
		cout << "l  ���� ���� ����  l";
		cout << "---------------------------------" << endl;

		cout << "���� : ó���� 7���踦 ��� �ְ�, " << endl;
		cout << "������ 8�� ��  �� ���� ���� ��� �ش�." << endl;
		cout << "�׸��� ������ ��ȣ�� ������." << endl;
		cout << "---------------------------------" << endl;
		cout << "�غ��ϰ� �ƹ� Ű�� ������." << endl;
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

		cout << "���� �����ּ���";
		int n;
		cin >> n;
		if (n == randValue)
		{
			cout << "���ϼ̽��ϴ�";
		}
		else
		{
			cout << "Ʋ�Ƚ��ϴ�. ������" << sound[randValue] << "�Դϴ�.";
		}
		int end;
		cout << "������ �������� 0�� �Է��ϼ���" << endl;
		cin >> end; 
		if (end == 0)
			break;

	}
	

	return 0;
}