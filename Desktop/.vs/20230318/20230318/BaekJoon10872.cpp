#include <iostream>
using namespace std;

int Factorial(int n)
{
	if (n < 1)
	{
		return 1;
	
	
	}
	return Factorial(n - 1);
}

int main(void)
{
	int n;

	cin >> n;
	return 0;
}