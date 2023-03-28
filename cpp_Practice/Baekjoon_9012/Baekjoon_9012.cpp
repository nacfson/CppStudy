#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	int size;
	cin >> size;

	vector<char> vpsVector;
	vector<string> valueVector;
	
	for (int i = 0; i < size; i++)
	{
		string value;
		cin >> value;
		valueVector.push_back(value);
	}
	//cout << valueVector.size();
	for (int i = 0; i < valueVector.size(); i++)
	{
		bool canCheck = true;
		for (int j = 0; j < valueVector[i].size(); j++)
		{
			if (!canCheck) continue;
			if (valueVector[i][j] == '(')
			{
				vpsVector.push_back('(');
			}
			else if (valueVector[i][j] == ')')
			{
				if (!vpsVector.empty())
				{
					vpsVector.pop_back();
				}
				else
				{
					//cout << "valueVector: " << valueVector[i][j];
					cout << "NO" << endl;
					canCheck = false;
					vpsVector.clear();
				}
			}
		}
		if (canCheck)
		{
			if (vpsVector.empty())
			{
				cout << "YES" << endl;
				vpsVector.clear();
			}
			else
			{
				cout << "NO" << endl;
				vpsVector.clear();
			}
		}

	}
	
	return 0;

}
