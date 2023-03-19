#include <iostream>
using namespace std;
int result = 1;
int Factorial(int n)
{
	if (n < 1)
	{
		return 1;
	}
	result *= n;
	return Factorial(n - 1);
}
int main(void)
{
	int n;
	cin >> n;
	Factorial(n);
	cout << result;
	return 0;
}