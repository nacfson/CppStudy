#include <iostream>
using namespace std;
class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) : real{ r }, imag{ i }{};

	friend Complex ComplexAdd(Complex c1,Complex c2);
	void Print() {
		cout << real << "+" << imag << "i";
	}
private :
	double real, imag;
};

Complex ComplexAdd(Complex c1, Complex c2) {
	Complex c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	return c;
}
int main(void) {
	Complex c1{ 3,4 },c2{5,6},c3;
	c3 = ComplexAdd(c1, c2);
	c3.Print();
	return 0;
}