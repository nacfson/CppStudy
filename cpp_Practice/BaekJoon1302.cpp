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
		if (arrMap.find(arr[i]) != arrMap.end())
		{
			arrMap[arr[i]]++;
		}
		else
		{
			arrMap.insert({ arr[i], 1 });
		}
	}

	
	int count = 0;
	string value;
	bool same = false;
	for (auto& ite : arrMap)
	{
		if (count == 0)
		{
			count = ite.second;
			value = ite.first;
		}
		if(count < ite.second)
		{
			count = ite.second;
			value = ite.first;
		}
	}

	cout << value;

	return 0;
}