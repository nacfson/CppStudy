#include <iostream>
using namespace std;
void Shuffle(int arr[])
{
	for (int i = 0; i < 100; i++)
	{
		int n = rand()% 100 + 1;
		int temp = arr[n];
		arr[n] = arr[n+1];
		arr[n+1] = temp;
	}
}

int main()
{
	int arr[100];
	int maxCount;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++)
	{
		arr[i] = i + 1;
	}

	
	Shuffle(arr);
	maxCount = arr[0];
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (maxCount < arr[i+1])
		{
			maxCount = arr[i + 1];
		}
	}

	cout << maxCount;
}

