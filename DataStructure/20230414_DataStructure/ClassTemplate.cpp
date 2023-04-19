#include <iostream>
using namespace std;

template <class T>
const double Circle<T>::PI = 3.14;

template <class T>
class Circle {
	T x,y,radius;

public :
	const static double PI;
	Circle<T>(T x, T y, T radius) : x{ x }, y{ y }, radius{ radius }{};
	double GetArea() {
		return radius * radius * PI;
	}
};
int main(void) {
	Circle<int> c1{ 1,1,5 };
	cout << c1.GetArea() << endl;
	return 0;
}