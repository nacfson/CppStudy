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
		if (arrMap[arr[i]] > 0)
		{
			arrMap[arr[i]]++;
		}
		else
		{
			arrMap.insert({arr[i],1});
		}
	}
	for (auto& d : arrMap)
	{
		cout << d.first << endl;
		cout << d.second << endl;
	}

	//int count = 0;
	//string value;
	//bool same = false;
	//for (auto& ite : arrMap)
	//{
	//	if (count < ite.second)
	//	{
	//		count = ite.second;
	//		value = ite.first;
	//	}
	//	else if (count == ite.second)
	//	{
	//		arr2.push_back(value);
	//		arr2.push_back(ite.first);
	//		cout << value << "//" << endl;
	//		cout << ite.first << "//" << endl;
	//		value = Sort(arr2.size(), arr2);
	//		break;
	//	}
	//}

	//cout << value;

	return 0;
}