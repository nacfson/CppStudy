#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	for (int i = 0; i < n - 1; i++)
	{
		arr.erase(arr.begin());
		arr.push_back(arr[0]);
		arr.erase(arr.begin());
	}
	cout << arr[0];
	
	return 0;
}