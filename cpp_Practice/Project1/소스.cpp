#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main(void)
{
	string sound[8] = { "��(1)","��(2)","��(3)" ,"��(4)" ,"��(5)" ,"��(6)" ,"��(7)" ,"��(8)" };
	float soundValueArr[8] = { 523.25,587.33,659.26,698.46,783.99,880,987.77,1046.50 };
	srand((unsigned int)time(NULL));
	cout << "---------------------------------" << endl;
	cout << "l  ���� ���� ����  l";
	cout << "---------------------------------" << endl;

	cout << "���� : ó���� 7���踦 ��� �ְ�, " << endl;
	cout << "������ 8�� ��  �� ���� ���� ��� �ش�." << endl;
	cout << "�׸��� ������ ��ȣ�� ������." << endl;
	cout << "---------------------------------" << endl;
	cout << "�غ��ϰ� �ƹ� Ű�� ������." << endl;
	//int a = 0;
	//_getch();
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
		system("cls");
		cout << i << "..." << endl;

		Sleep(250);
	}

	int randValue = rand() % 8;

	Beep(soundValueArr[randValue], 500);

	cout << "���� �����ּ���";


	return 0;
}