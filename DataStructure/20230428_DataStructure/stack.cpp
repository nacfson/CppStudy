//#include <iostream>
////#define SIZE 10
//#include <stack>
//using namespace std;
//class Stack {
//public:
//	static const int SIZE = 10;
// 
//	Stack(char ch = ' ');
//	void Push(char ch);
//	char Pop();
//private:
//	int topIndex;
//	char name;
//	char stackArr[SIZE];
//};
//
//int main(void) {
//	Stack s1{ 'A' }, s2{ 'B' };
//
//	s1.Push('d');
//	s1.Push('a');
//	s1.Push('t');
//	s1.Push('a');
//
//	s2.Push('s');
//	s2.Push('t');
//	s2.Push('a');
//	s2.Push('c');
//	s2.Push('k');
//	for (int i = 0; i < 5; i++) {
//		cout << "Pop s1:" << s1.Pop() << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < 5; i++) {
//		cout << "Pop s2:" << s2.Pop() << endl;
//	}
//
//	return 0;
//}
//
//Stack::Stack(char ch= ' ') {
//	name = ch;
//	topIndex = -1;
//}
//void Stack::Push(char ch) {
//	if (topIndex + 1 > SIZE) {
//		cout << "Stack " << name << "is full" << endl;
//	}
//	else {
//		stackArr[topIndex++] = ch;
//	}
//}
//char Stack::Pop() {
//	if (topIndex == -1) {
//		cout << "Stack " << name << "is empty" << endl;
//	}
//	else {
//		return stackArr[topIndex--];
//	}
//}