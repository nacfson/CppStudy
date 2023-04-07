#include <iostream>
#include <string>
using namespace std;
class Box {
	double length;
	double width;
	double height;
public:
	Box(double l = 0.0, double w = 0.0, double h = 0.0) : length{ l }, width{ w }, height{ h } { }
	double getVolume() {
		return length * width * height;
	}
	Box operator+(const Box& box) {
		Box b;
		b = {this->length + box.length , this->width + box.width, this->height + box.height };
		return b;
	}
	bool operator==(Box& box) {
		bool result = false;
		result = box.getVolume() == this->getVolume();
		return result;
	}
	bool operator<(Box& box) {
		return this->getVolume() < box.getVolume() ? true : false;
	}
};

int main(void) {
	Box a(10, 10, 10), b(20, 20, 20), c;
	c = a + b;
	cout << c.getVolume() << endl;
	cout << to_string(a == b) << endl;
	cout << to_string(a < b) << endl;
	return 0;
}