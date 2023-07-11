//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int cup[3];
//	int mixCnt;
//	  
//	for (int i = 0; i < 3; i++) {
//		cup[i] = -1;
//	}
//	cup[0] = 0;
//
//
//	cin >> mixCnt;
//
//	for (int i = 0; i < mixCnt; i++) {
//		int n, m;
//		cin >> n >> m;
//
//		if (cup[n - 1] == 0 || cup[m - 1] == 0) {
//			int temp = cup[n-1];
//			cup[n - 1] = cup[m - 1];
//			cup[m - 1] = temp;
//		}
//	}
//
//	for (int i = 0; i < 3; i++) {
//		if (cup[i] == 0) {
//			cout << i + 1;
//			break;
//		}
//	}
//
//	return 0;
//}