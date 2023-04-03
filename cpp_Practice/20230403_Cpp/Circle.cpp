#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            cout << " ";
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        for (int k = (n-1) * 2 - 1; k > (i * 2); k--)
        {
            cout << "*";
        }
        cout << endl;
    }
	return 0;
}