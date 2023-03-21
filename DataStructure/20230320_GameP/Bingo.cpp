#include <iostream>
#include <Windows.h>
using namespace std;
enum class AI_MODE
{
	AM_EASY =1,
	AM_NORMAL
};
void RenderNumber(int iNumber[],int iBingo)
{
	cout << "===========================================" << endl;
	cout << "|\t 빙고 게임 \t" << endl;
	cout << "===========================================" << endl;
	cout << "빙고줄이 5줄 이상이 되면 게임에서 승리합니다." << endl;
	cout << "===========================================" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (iNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else
				cout << iNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
	cout << "BingoLine: " << iBingo << endl;

}

void Init(int* iNumber)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25 ; i++)
	{
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24 + 1;
		idx2 = rand() % 24 + 1;
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
}
void Update(int* _pNumber, int& input)
{
	for (int i = 0; i < 25; i++)
	{
		if (input == _pNumber[i])
		{
			_pNumber[i] = INT_MAX;
		}
	}
}
int CountBingo(int *pNumber)
{
	int iCheckBingo = 0;
	int iHorStar = 0, iVerStar = 0,
		iLTStar = 0,
		iRTStar = 0;
	for (int i = 0; i < 5; i++)
	{
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++)
		{
			if (pNumber[i*5+j] == INT_MAX)
			{
				iHorStar++;
			}
			if (pNumber[j * 5 + i] == INT_MAX)
			{
				iVerStar++;
			}
		}
		if (iHorStar == 5)
			iCheckBingo++;
		if (iVerStar == 5)
			iCheckBingo++;
	}
	
	for (int i = 0; i < 25; i += 6)
	{
		if (pNumber[i] == INT_MAX)
		{
			iLTStar++;
		}
	}
	for (int i = 0; i < 21; i += 4)
	{
		if (pNumber[i] == INT_MAX)
		{
			iRTStar++;
		}
	}
	if (iLTStar == 5)
		iCheckBingo++;
	if (iRTStar == 5)
		iCheckBingo++;
	
	return iCheckBingo;
}
int main(void)
{
	int iNumber[25] = {};
	int iBingo = 0;
	int input;

	Init(iNumber);
	while (1)
	{
		system("cls");
		RenderNumber(iNumber, iBingo);
		if (iBingo > 4)
		{
			cout << "게임에서 승리하였습니다.";
			break;
		}
		cout << "숫자를 입력하세요.(0: 종료)" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else if (input < 1 || input > 25)
		{
			cout << "잘못입력하였습니다." << endl;
			continue;
		}	
		//Update(), 칸을 채워준다 ,채워진 칸인지 확인.
		//정답처리
		Update(iNumber, input);
		iBingo = CountBingo(iNumber);
	}

	return 0;
}