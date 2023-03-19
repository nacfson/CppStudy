#include <iostream>
using namespace std;
int main(void)
{
	int n;
	int m;

	cin >> n >> m;

	int arr[100][100];
	int arr2[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] + arr2[i][j] << ' ';
		}
		cout << endl;
	}


	return 0;
}
