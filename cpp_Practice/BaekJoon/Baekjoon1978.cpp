//#include <iostream>
//using namespace std;
//
//bool isMinority(int num) {
//	if (num < 2) return false;
//	for (int i = num - 1; i > 1; i--) {
//		if (num % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		if (isMinority(tmp)) cnt++;
//	}
//
//	cout << cnt;
//
//
//	return 0;
//}