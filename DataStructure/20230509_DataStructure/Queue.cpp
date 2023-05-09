#include <iostream>
#include <queue>
using namespace std;
void Command(string value, queue<int>& q2) {
	if (value == "push") {
		int pushValue;
		cin >> pushValue;
		q2.push(pushValue);
	}
	else if (value =="pop") {
		if (q2.empty()) {
			q2.push(-1);
		}
		else {
			q2.pop();
		}
	}
	else if (value == "size") {
		q2.push(q2.size());
	}
	else if (value == "empty") {
		q2.push(q2.empty());
	}
	else if (value == "front") {
		q2.push(q2.front());
	}
	else if (value == "back") {
		q2.push(q2.back());
	}
}
int main(void) {
	int count;
	queue<int> q2;
	vector<string> vec;
	cin >> count;

	for (int i = 0; i < count; i++) {
		string value;
		cin >> value;
		vec.push_back(value);
	}
	for (int i = 0; i < q2.size(); i++) {
		cout << q2.front() << endl;
		q2.pop();
	}

	return 0;
}