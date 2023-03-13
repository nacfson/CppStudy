#include <iostream>

using namespace std;
void TurnBaseBall(int& turn)
{
	if (turn == 1)
	{
		cout << "Player1�� �����Դϴ�." << endl << "1 ~ 9 ���� ���� �� ���� 3���� �Է��ϼ���.(0 : ����): ";
		turn++;

	}
	else
	{
		cout << "Player2�� �����Դϴ�." << endl << "1 ~ 9 ���� ���� �� ���� 3���� �Է��ϼ���.(0 : ����): ";
		turn--;
	}
}

bool CanCheck(int iInput[])
{
	if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
	{
		return false;
	}
	//���� ó��
	else if (iInput[0] < 1 || iInput[0] > 9 || iInput[1] < 1 || iInput[1] > 9 || iInput[2] < 1 || iInput[2] > 9)
	{
		cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�. 1 ~ 9 ������ ���ڸ� �Է��ϼ���." << endl;
		return true;
	}
	else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[0] == iInput[2])
	{
		cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
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
	cout << "Player1�� ���ڸ� �Է��ϼ���" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> iPlayerArr[i];
	}
	cout << "Player2�� ���ڸ� �Է��ϼ���" << endl;
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
			cout << "�����մϴ�";
			break;
		}
		else if (iStrike == 0 && iBall == 0)
		{
			cout << "Out�Դϴ�.";
		}

		cout << "Strike: " << iStrike << "\t" << "Ball: " << iBall << endl;
	}
	return 0;
}