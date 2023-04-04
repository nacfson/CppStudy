//#include <iostream>
//using namespace std;
//class Box
//{
//private :
//	double length, width, height;
//public :
//	Box(double l = 0, double w = 0, double h = 0) : length{ l }, width{ w }, height{ h }{};
//
//	void Display()
//	{
//		cout << "(" << length << ", " << width << ", " << height << ")" << endl;
//	}
//	Box& operator=(const Box& b2)
//	{
//		this->length = b2.length;
//		this->width = b2.width;
//		this->height = b2.height;
//		return *this;
//	}
//};
//
//int main(void)
//{
//	Box b1{30.0,30.0,60.0}, b2,b3;
//	b1.Display();
//	b2 = b1;
//	b2.Display();
//
//	b3 = b2 = b1;
//	return 0;
//}