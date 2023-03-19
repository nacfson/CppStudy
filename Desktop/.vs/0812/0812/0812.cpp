
#include <iostream>
#include <string>
using namespace std;
void StrCount()
{
	string str;
	getline(cin, str);

	int a =0 , b = 0, c = 0;
	for (auto count :str)
	{
		switch (count)
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
			default:
				break;
		}
	};
	cout << "a,A : " << a << "b,B : " << b << "c,C : " << c;
}
int main()
{
	StrCount();
}

