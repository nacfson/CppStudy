#include <iostream>
using namespace std;

int main(void)
{
	int arr[9][9];
	int max;
	int n = 1, m = 1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (i == 0 && j == 0)
			{
				max = arr[i][j];
			}
			else if (max < arr[i][j])
			{
				max = arr[i][j];
				n = i + 1;
				m = j + 1;
			}
		}
	}


	cout << max << endl << n << ' ' << m;
	return 0;
}