#include <iostream>
using namespace std;

int main()
{
	int paperCount;
	int result = 0;
	int bigPaper[100][100];
	int x = 0, y = 0;

	cin >> paperCount;

	fill(&bigPaper[0][0], &bigPaper[99][100], 0);

	for (int j = 0; j < paperCount; j++)
	{
		cin >> x >> y;
		for (int i = 0; i < 10; i++)
			fill(&bigPaper[x + i][y], &bigPaper[x + i][y + 10], 1);
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (bigPaper[i][j] == 1)
			{
				result++;
			}
		}
	}

	cout << result;
	return 0;
}
