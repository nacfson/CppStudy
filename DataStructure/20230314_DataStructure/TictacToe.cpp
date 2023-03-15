#include <iostream>
using namespace std;

void MapArr(int turn, int mapArr[][3], int n, int m)
{
	mapArr[n][m] = turn;
}
bool CheckLines(int mapArr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (mapArr[i][0] == mapArr[i][1] && mapArr[i][1] == mapArr[i][2])
		{
			cout << "1" <<endl;
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (mapArr[0][i] == mapArr[1][i] && mapArr[1][i] == mapArr[2][i])
		{
			cout << "2" << endl;
			return true;
		}
	}
	if (mapArr[0][0] == mapArr[1][1] && mapArr[1][1] == mapArr[2][2])
	{
		cout << "3" << endl;
		return true;

	}
	if (mapArr[1][1] == mapArr[2][0] && mapArr[0][2] == mapArr[1][1])
	{
		cout << "4" << endl;
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
	int turn = 10;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mapArr[i][j] = rand();
		}
	}
	while (true)
	{
		cin >> n >> m;
		MapArr(turn, mapArr, n, m);
		if (CheckLines(mapArr))
		{
			break;
		}
	}
	cout << "Player: " << turn << "이 이겼습니다.";
	return 0;
}