#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main(void)
{
	string sound[8] = { "도(1)","레(2)","미(3)" ,"파(4)" ,"솔(5)" ,"라(6)" ,"시(7)" ,"도(8)" };
	float soundValueArr[8] = { 523.25,587.33,659.26,698.46,783.99,880,987.77,1046.50 };
	srand((unsigned int)time(NULL));
	cout << "---------------------------------" << endl;
	cout << "l  절대 음감 게임  l";
	cout << "---------------------------------" << endl;

	cout << "설명 : 처음에 7음계를 들려 주고, " << endl;
	cout << "다음에 8개 중  한 개의 음을 들려 준다." << endl;
	cout << "그리고 그음을 번호를 맞힌다." << endl;
	cout << "---------------------------------" << endl;
	cout << "준비하고 아무 키나 누른다." << endl;
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

	cout << "답을 맞춰주세요";


	return 0;
}