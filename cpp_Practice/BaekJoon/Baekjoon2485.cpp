//#include <iostream>
//
//using namespace std;
//
//
//int main(void){
//	int n;
//	cin >> n;
//
//	int arr[1000000000];
//
//	int minVal = 0;
//	int maxCnt = 0;
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		int compareVal = arr[i + 1] - arr[i];
//		if (compareVal < minVal) compareVal = minVal;
//	}
//
//	for (int i = 0; i < n; i++) {
//		int compareVal = arr[i + 1] - arr[i];
//		if (compareVal == minVal) continue;
//		maxCnt += static_cast<int>(compareVal / minVal);
//	}
//
//	cout << maxCnt;
//	return 0;
//}