//#include <iostream>
//using namespace std;
//class Complex
//{
//public :
//	double real, imag;
//	Complex(double real = 0, double imag = 0) : real{ real }, imag{ imag } {};
//
//	void Print()
//	{
//		cout << real << "+" << imag << "i" << endl;
//	}
//};
//
//Complex Add(const Complex& c1,const Complex& c2)
//{
//	Complex temp;
//	temp.real = c1.real + c2.real;
//	temp.imag = c1.imag + c2.imag;
//	return temp;
//}
//
//int main(void)
//{
//	Complex c1{ 1,2 }, c2{ 3,4 };
//	Complex t;
//	t = Add(c1, c2);
//	t.Print();
//	return 0;
//}