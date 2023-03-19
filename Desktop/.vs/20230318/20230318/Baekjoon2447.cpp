#include <iostream>
using namespace std;

void DrawStar(int n)
{
	if (n > 1)
	{
		DrawStar(n - 1);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i % 3 == 1 && j % 3 == 1)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

int main(void)
{
	int n;
	cin >> n;

	DrawStar(n);


	return 0;
}