#include <iostream>
#include <map>
#include <vector>
using namespace std;
string Sort(int n,vector<string> arr)
{
	string a;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 == n)
		{
			break;
		}
		if (arr[i] > arr[i + 1])
		{
			a = arr[i + 1];
		}
	}
	return a;
}
int main()
{
	int n= 0;
	cin >> n;
	string* arr = new string[n];
	vector<string> arr2;
  	map<string, int> arrMap;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i + 1 == n)
		{	
			break;
		}
		if (arr[i] == arr[i + 1])
		{
			arrMap[arr[i]]++;
		}
	}

	int count = 0;
	string value;
	bool same = false;
	for (auto& ite : arrMap)
	{
		if (count < ite.second)
		{
			count = ite.second;
			value = ite.first;
			same = false;
		}
		else if (count == ite.second)
		{
			arr2.push_back(value);
			arr2.push_back(ite.first);
			same = true;
		}
	}
	if (same)
	{
		cout << Sort(arr2.size(), arr2);
	}
	else
	{
		cout << value;
	}
	return 0;
}