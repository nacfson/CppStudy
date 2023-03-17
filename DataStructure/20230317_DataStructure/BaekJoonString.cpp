#include <iostream>
#include <string>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
int main(void)
{
	//int num;
	//cin >> num;

	//for (int i = 0; i < num; i++)
	//{
	//	string str;
	//	cin >> str;
	//	cout << str[0] << str[str.size() - 1] << endl;
	//}


	//char value;
	//cin >> value;
	//cout << value - '0' + 48;


	//int count;
	//int result = 0;
	//cin >> count;
	//int* arr = new int[count];

	//for (int i = 0; i < count; i++)
	//{
	//	scanf("%1d", &arr[i]);
	//	result += arr[i];
	//}
	// 
	//cout << result;

	//int num;
	//string str;
	//int count;
	//cin >> num;
	//for (int k = 0; k < num; k++)
	//{
	//	cin >> count;
	//	cin >> str;
	//	for (int i = 0; i < str.size(); i++)
	//	{
	//		for (int j = 0; j < count; j++)
	//		{
	//			cout << str[i];
	//		}
	//	}
	//	cout << endl;

	//}



		string str;
		int count = 0;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0 || i == str.size() - 1)
				continue;
			if (str[i] == ' ')
			{
				count++;
			}
		}
		if (count != 0)
		{
			cout << count + 1;
		}
		else
		{
			cout << 0;
		}
	


}