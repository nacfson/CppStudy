//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//int compare(const void* a, const void* b)
//{
//	const int* x = (int*)a;
//	const int* y = (int*)b;
//
//	if (*x > *y)
//		return 1;
//	else if (*x < *y)
//		return -1;
//
//	return 0;
//}
//
//int main(void) {
//	int n;
//	int nArr[100000];
//	int m;
//
//	int left = 0;
//	int right;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int input;
//		cin >> input;
//		nArr[i] = input;
//	}
//	//qsort(nArr.begin(), nArr.end());
//	//qsort(nArr.size());
//	qsort(nArr, n, sizeof(int), compare);
//
//
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int input;
//		cin >> input;
//		bool result = false;
//
//		left = 0; 
//		right = n - 1;
//		while (left <= right) {
//			int midValue = (int)((left + right) / 2);
//
//			if (nArr[midValue] == input) {
//				result = true;
//				break;
//			}
//			else if (nArr[midValue] < input) {
//				left = midValue + 1;
//				continue;
//			}
//			else {
//				right = midValue - 1;
//				continue;
//			}
//		}
//		cout << result ? 1 : 0;
//		cout << endl;
//	}
//
//
//	return 0;
//}