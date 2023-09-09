//#include <iostream>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//int main(void) {
//	long min,max;
//
//	int nnCnt = 0;
//	cin >> min >> max;
//
//	bool visited[1000001] = {};
//
//	for (int i = 2; i <= sqrt(max); i++) {
//		if (visited[i - min] == true) continue;
//		cout << "I Value:  " << i;
//		nnCnt++;
//		for (int j = i * i; j <= (max); j += i) {
//			visited[j - min] = true;
//		}
//	}
//
//	cout << nnCnt;
//	return 0;
//}