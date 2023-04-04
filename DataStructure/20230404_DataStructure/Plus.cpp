#include <iostream>
#include <string>
using namespace std;

class MyVector
{
private :
	double x, y;
public :
	MyVector(double x = 0.0, double y = 0.0) : x{ x }, y{ y }{};
	string toString()
	{
		return "(" + to_string(x) + "," + to_string(y) + ")";
	}
	MyVector operator+(const MyVector& v2);
};

MyVector MyVector::operator+(const MyVector& v2)
{
	MyVector v;
	v.x = this->x + v2.x;
	v.y = this->y = v2.y;
	return v;
}

int main(void)
{
	MyVector a{ 3,3 };
	MyVector b{ 3,3 };
	return 0;
}