#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	//stack<char> s1;
	//string str;
	//cin >> str;
	//for (int i = 0; i < str.size(); i++) {
	//	s1.push(str[i]);
	//}

	//for (int i = 0; i < str.size(); i++) {
	//	cout << s1.top();
	//	s1.pop();
	//}
	 
	
	//stack<int> iStack;
	//int n;
	//try {
	//	cout << "10진수를 입력하세요.";
	//	cin >> n;
	//	if (n < 0) {
	//		throw new exception;
	//	}
	//}
	//catch(exception ex) {
	//	cout << "음수를 입력하였습니다. 양수를 입력하세요";
	//}

	//while (n / 2 > 0) {
	//	iStack.push(n%2);
	//	n = n / 2;
	//}
	//iStack.push(n % 2);

	//cout << "2진수로 변환한 값: ";
	//int size = iStack.size();

	//for (int i = 0; i < size; i++) {
	//	cout << iStack.top();
	//	iStack.pop();
	//}

	stack<char> comma;

	int n;
	cin >> n;
	int cnt = 0;
	while (n) {
		comma.push(n % 10 + '0');
		cnt++;

		n /= 10;
		if (n != 0 && cnt == 3) {
			comma.push(',');
			cnt = 0;
		}

	}

	while (!comma.empty()) {
		cout << comma.top();
		comma.pop();
	}
	return 0;
}