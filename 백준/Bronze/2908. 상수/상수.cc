#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string n, m;
    int a, b;
    cin >> n >> m;

    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());

    a = stoi(n);
    b = stoi(m);

    if (a > b)
        cout << a << endl;
    else
        cout << b << endl;

    return 0;
}