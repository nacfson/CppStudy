	#include <iostream>
	#include <vector>
	using namespace std;

	void Shuffle(vector<int> &arr,int n)
	{
		for (int i = 0; i < n; i++)
		{
			arr.erase(arr.begin());
			rotate(arr.begin(), arr.begin() + 1, arr.begin() + n);
		}
	}
	int main(void)
	{
		int n;
		cin >> n;
		vector<int> arr;

		for (int i = 0; i < n; i++)
		{
			arr.push_back(i + 1);
		}
		Shuffle(arr,n);
		cout << arr[0];
		return 0;
	}