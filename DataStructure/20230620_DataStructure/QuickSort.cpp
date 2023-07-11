//#include <iostream>
//using namespace std;
//
//	
//int main(void) {
//	int arr[100];
//	int i, j, tmp;
//
//	int arrCnt;
//	cin >> arrCnt;
//	for (int i = 0; i < arrCnt; i++) {
//		cin >> arr[i];
//	}
//
//	for (i = 0; i < arrCnt; i++) {
//		tmp = arr[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (tmp < arr[j]) arr[j + 1] = arr[j];
//			else break;
//		}
//		arr[j + 1] = tmp;
//	}
//
//	for (int i = 0; i < arrCnt; i++) {
//		cout << arr[i];
//	}
//	return 0;
//}