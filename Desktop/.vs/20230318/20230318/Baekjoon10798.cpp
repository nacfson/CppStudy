#include <iostream>
using namespace std;
int main(void)
{
	char arr2[5][15];
	char word[20];
	for (int i = 0; i < 5; i++)
	{
		cin >> word;

		for (int j = 0; j < strlen(word); j++)
		{
			arr2[i][j] = word[j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (arr2[i][j] != ' ')
			{
				cout << arr2[i][j];
			}
		}
	}
	return 0;
}