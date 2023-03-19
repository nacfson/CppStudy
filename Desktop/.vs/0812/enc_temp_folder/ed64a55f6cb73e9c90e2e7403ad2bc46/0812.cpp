
#include <iostream>
#include <string>
using namespace std;
void StrCount(string& std,int &a,int &b,int &c)
{
	for (auto arr :std)
	{
		switch (std[arr])
		{
		case 'a':
		case 'A':
			a++;
			break;
		case 'b':
		case 'B':
			b++;
			break;
		case 'c':
		case 'C':
			c++;
			break;
		}
	};
}
int main()
{
	int a, b, c;
	string str;
	cin >> str;
	StrCount(str,a,b,c);
	cout << "a,A" << a << "b,B" << b << "c ,C" << c;
}

