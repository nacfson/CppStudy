#include <iostream>
using namespace std;

const float PI = 3.14f;

double Circle(int r)
{
    double area;
    area = r * r * PI;
    return area;
}
int main()
{
    int r;
    cin >> r;
    cout << Circle(r);
    return 0;
}



