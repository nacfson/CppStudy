//#include <iostream>
//using namespace std;
//
//class Queue {
//	int* _buf;
//	int _qSize;
//	int _front = -1;
//	int _rear = 0;
//
//public:
//	void InitQueue(int init);
//	void Enqueue(int data);
//	int IsEmpty();
//	int IsFull();
//	int Dequeue();
//};
//
//int main(void) {
//	Queue q1;
//	q1.InitQueue(10);
//	for (int i = 1; i <=11; i++) {
//		cout << i << "입력 \n";
//		q1.Enqueue(i);
//	}
//	cout << endl;
//	while (q1.IsEmpty()) {
//		cout << q1.Dequeue() << "출력 \n";
//	}
//	cout << endl;
//	return 0;
//}
//
//void Queue::InitQueue(int qSize) {
//	_qSize = qSize;
//	_buf = new int[_qSize];
//	_front = _rear = -1;
//}
//
//int Queue::IsFull() {
//	return _rear == _qSize - 1;
//}
//
//int Queue::IsEmpty() {
//	return _front == _rear;
//}
//int Queue::Dequeue() {
//	if (IsEmpty()) {
//		cout << "Queue is Empty!";
//		return -1;
//	}
//	return _buf[++_front];
//}
//void Queue::Enqueue(int data) {
//	if (IsFull()) {
//		cout << "Queue is Full!";
//		return;
//	}
//	_buf[++_rear] = data;
//}