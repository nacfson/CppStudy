//#include <iostream>
//using namespace std;
//
//class Box {
//private:
//	double length;
//	double width;
//	double height;
//public:
//	static int count;
//
//	double Volume() {
//		return length * width * height;
//	}
//	Box(double length = 0.0, double width = 0.0, double height = 0.0) :length{ length }, width{ width }, height{ height }{
//		count += 1; };
//	friend Box operator+(Box& box1,Box& box2);
//	friend bool operator==(Box& box1, Box& box2);
//	friend bool operator<(Box& box1, Box& box2);
//};
//
//Box operator+(Box& box1,Box& box2) {
//	Box b;
//	b.length = box1.length + box2.length;
//	b.width = box1.width + box2.width;
//	b.height = box1.height + box2.height;
//	return b;
//}
//bool operator==(Box & box1, Box & box2) {
//	bool result = false;
//	if (box1.Volume() == box2.Volume()) {
//		result = true;
//	}
//	return result;
//}
//bool operator<(Box& box1, Box& box2) {
//	bool result = false;
//	if (box1.Volume() < box2.Volume())
//		result = true;
//	return result;
//}
//
//int Box::count = 0;
//
//int main(void) {
//	Box Box1(1.0, 2.0, 3.0);
//	Box Box2(1.0, 2.0, 5.0);
//
//	cout << "ÀüÃ¼ °´Ã¼ ¼ö: " << Box::count << endl;
//
//
//	return 0;
//}