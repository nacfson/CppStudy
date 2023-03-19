#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;


int main(void)
{
	char arr2[5][15];
	char word[15];


	for (int i = 0; i < 5; i++)
	{
		cin >> word;
		for (int j = 0; j < 15; j++)
		{
			arr2[i][j] = word[j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (arr2[j][i] != ' ')
			{
				if (arr2[j][i] != '\0')
				{
					cout << arr2[j][i];
				}
			}
		}
	}

	return 0;
}