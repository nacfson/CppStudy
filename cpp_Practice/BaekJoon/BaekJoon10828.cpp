//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	stack<int> stac;
//
//	for (int i = 0; i < n; i++) {
//		string input;
//		cin >> input;
//
//		if (input == "push") {
//			int i;
//			cin >> i;
//			stac.push(i);
//		}
//		else if (input == "pop") {
//			if (stac.empty()) cout << -1 << endl;
//			cout << stac.top() << endl;
//			stac.pop();
//		}
//		else if (input == "size") {
//			cout << stac.size() << endl;
//		}
//		else if (input == "empty") {
//			cout << stac.empty() ? 1 : 0;
//			cout << endl;
//		}
//		else if (input == "top") {
//			if (stac.empty()) cout << -1 << endl;
//			cout << stac.top() << endl;
//		}
//	}
//
//
//	return 0;
//}