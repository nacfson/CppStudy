#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int a, b, c, d;

	cin >> a >> b >> c >> d;
	if (a > b)
		swap(a, b);
		if (a <= c  && c <= b && a <= d && d <= b)
	{
		cout << "not cross";
	}
	else
	{
		if (a < c && c < b || a < d && d < b)
		{
			cout << "cross";
		}
		else
		{
			cout << "not cross";
		}
	}
	return 0;
}