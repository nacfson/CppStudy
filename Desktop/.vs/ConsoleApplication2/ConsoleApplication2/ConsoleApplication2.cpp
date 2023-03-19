#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int Solution(int n1, int n2)
{
	double a = (double)n1 / n2 * 1000;
	return a;
}
int main()
{
	cout << Solution(7, 3);
}



