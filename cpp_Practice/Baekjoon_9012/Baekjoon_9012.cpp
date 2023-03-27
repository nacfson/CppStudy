#include <iostream>
using namespace std;

int main(void)
{
	int size;
	cin >> size;
	

	int rVpsCnt {0};
	int lVpsCnt{ 0 };
	
	string *vpsArray = new string[size];

	for (int i = 0; i < size; i++)
	{
		string value{NULL};
		cin >> value;
		vpsArray[i] = value;
	}

	for (int i = 0; i < size; i++)
	{
		lVpsCnt = 0;
		rVpsCnt = 0;
		for (int j = 0; j < vpsArray[i].size(); j++)
		{
			if (vpsArray[i][j] == '(')
			{
				lVpsCnt++;
			}
			if(vpsArray[i][j] == ')')
			{
				rVpsCnt++;
			}
		}
		if (lVpsCnt != rVpsCnt)
		{
			cout << "NO" << endl;
		}
		else
		{
			if (vpsArray[i][vpsArray[i].size()] == '(')
			{
				cout << "NO" << endl;
			}
			else
			{
				int saveValueArray[50];
				int index = 0;
				for (int k = 0; k < vpsArray[i].size(); k++)
				{
					if (vpsArray[i][k] == ')')
					{
						saveValueArray[index] = k;
						index++;z
					}
				}
				for (int z = 0; z < index; i++)
				{

				}
				cout << "YES" << endl;
			}

		}
	}
	return 0;

}
