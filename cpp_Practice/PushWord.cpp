#include <iostream>
using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] + n > 122)
		{
			s[i] = s[i] + n - 26;
		}
		else
		{
			s[i] = s[i] + n;
		}
	}
	cout << s;

	

	return 0;
}