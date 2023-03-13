#include <iostream>

using namespace std;
void TurnBaseBall(int& turn)
{
	if (turn == 1)
	{
		cout << "Player1의 차례입니다." << endl << "1 ~ 9 까지 숫자 중 숫자 3개를 입력하세요.(0 : 종료): ";
		turn++;

	}
	else
	{
		cout << "Player2의 차례입니다." << endl << "1 ~ 9 까지 숫자 중 숫자 3개를 입력하세요.(0 : 종료): ";
		turn--;
	}
}

bool CanCheck(int iInput[])
{
	if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
	{
		return false;
	}
	//예외 처리
	else if (iInput[0] < 1 || iInput[0] > 9 || iInput[1] < 1 || iInput[1] > 9 || iInput[2] < 1 || iInput[2] > 9)
	{
		cout << "잘못된 숫자를 입력하였습니다. 1 ~ 9 사이의 숫자를 입력하세요." << endl;
		return true;
	}
	else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[0] == iInput[2])
	{
		cout << "중복된 숫자를 입력하였습니다." << endl;
		return true;
	}
	else
	{
		return true;
	}
}
void CheckStrikeBall(int& iStrike, int& iBall,int iInput[],int iNumber[])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (iInput[i] == iNumber[j])
			{
				if (i == j)
				{
					iStrike++;
				}
				else
				{
					iBall++;
				}
			}
		}
	}
}

int main(void)
{
	int iPlayerArr[3];
	int iPlayer2Arr[3];
	int playerTurn = 1;
	cout << "Player1의 숫자를 입력하세요" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> iPlayerArr[i];
	}
	cout << "Player2의 숫자를 입력하세요" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> iPlayer2Arr[i];
	}

	system("cls");
	while (1)
	{
		int iStrike = 0, iBall = 0;
		int iInput[3];
		TurnBaseBall(playerTurn);
		for (int i = 0; i < 3; i++)
		{
			cin >> iInput[i];
		}

		if (!CanCheck(iInput))
		{
			break;

		}

		if (playerTurn== 1)
		{
			CheckStrikeBall(iStrike,iBall,iInput,iPlayerArr);
		}
		else
		{
			CheckStrikeBall(iStrike, iBall, iInput, iPlayer2Arr);
		}

		if (iStrike == 3)
		{
			system("cls");
			cout << "축하합니다";
			break;
		}
		else if (iStrike == 0 && iBall == 0)
		{
			cout << "Out입니다.";
		}

		cout << "Strike: " << iStrike << "\t" << "Ball: " << iBall << endl;
	}
	return 0;
}