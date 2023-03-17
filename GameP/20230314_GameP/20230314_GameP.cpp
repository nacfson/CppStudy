
#include <iostream>
#include<Windows.h>
using namespace std;
enum MODE //열거형
{
	EASY = 1,
	NORMAL,
	HARD	
};

int SleepAmount(int mode)
{
		switch (mode)
		{
		case EASY:
		{
			return 1000;
			break;
		}
		case NORMAL:
		{
			return 1000;
			break;
		}
		case HARD:
		{
			return 500;
			break;
		}
		}
}
int main()
{
	srand((unsigned int)time(NULL));
	int mode,count = 0;
	bool gameOver = false;
	cout << "숫자 기억 게임입니다. 모드를 선택하세요" << endl << "EASY: 1,NORMAL: 2,HARD: 3"<<endl;
	cin >> mode;

	int* randArr = new int[mode * 5];

	for (int i = 0; i < mode * 5; i++)
	{
		randArr[i] = rand() % 100 + 1;
	}

	while (count < mode * 5)
	{
		cout << randArr[count] << " ";
		Sleep(SleepAmount(mode));
		count++;
	}
	system("cls");

	for (int i = 0; i < mode * 5; i++)
	{
		int n;
		cin >> n;
		if (randArr[i] != n)
		{
			cout << "틀렸습니다.";
			gameOver = true;
			break;
		}
	}
	if (!gameOver)
	{
		cout << "정답";
	}

}
