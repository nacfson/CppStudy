#include <iostream>
using namespace std;
int Fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n < 3)
	{
		return 1;
	}
	return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(void)
{
	int n; 
	cin >> n;

	cout << Fibonacci(n);
	return 0;
}