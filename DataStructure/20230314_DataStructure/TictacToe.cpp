#include <iostream>
using namespace std;

void MapArr(int turn, int mapArr[3][3], int n, int m)
{
	mapArr[n][m] = turn;
}
bool CheckLines(int mapArr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (mapArr[i][0] == mapArr[i][1] && mapArr[i][1] == mapArr[i][2])
		{
			return true;
		}
		if (mapArr[0][i] == mapArr[1][i] && mapArr[1][i] == mapArr[2][i])
		{
			return true;
		}
	}
	if (mapArr[0][0] == mapArr[1][1] && mapArr[1][1] == mapArr[2][2])
	{
		return true;

	}
	if (mapArr[1][1] == mapArr[2][0] && mapArr[0][2] == mapArr[1][1])
	{
		return true;
	}
	return false;
}

void ChangeTurn(int& turn)
{
	if (turn == 1)
	{
		turn = 2;
	}
	else
	{
		turn = 1;
	}
}


int main(void)
{
	srand((unsigned int)time(NULL));
	int mapArr[3][3];
	int n, m;
	int turn = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mapArr[i][j] = rand() + 3;
		}
	}

	while (true)
	{
		cout << "(x, y) ÁÂÇ¥: ";
		cin >> n >> m;
		MapArr(turn, mapArr, n, m);
		cout << endl;
		for (int i = 0; i < 7; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << "---";
					cout << "|";
				}
				cout << "---";
			}
			else
			{
				for (int j = 0; j < 2; j++) {
					if (mapArr[i / 2][j] == 1 || mapArr[i / 2][j] == 2)
						cout << mapArr[i / 2][j] << "  |";
					else {
						cout << "   |";
					}
				}
			}
			cout << endl;
		}

		if (CheckLines(mapArr))
		{
			break;
		}
	}
	cout << "Player: " << turn << "ÀÌ ÀÌ°å½À´Ï´Ù.";
	return 0;
}