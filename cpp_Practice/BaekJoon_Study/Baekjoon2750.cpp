//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	int arr[1000000];
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n  - i; j++) {
//			if (arr[i] > arr[j]) {
//				int temp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << '\n';
//	}
//
//
//
//	return 0;
//}