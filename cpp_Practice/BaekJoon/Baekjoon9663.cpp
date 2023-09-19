//#include <iostream>
//#include <vector>
//#include <queue>
//#define MAX 15
//using namespace std;
//int n;
//int cnt = 0;
//int queen_map[MAX];
//
//bool promising(int row) {
//	for (int i = 0; i < row; i++) {
//		if (queen_map[row] == queen_map[i]
//			|| abs(row - i) == abs(queen_map[row] - queen_map[i])) {
//			return false;
//		}
//	}
//	return true;
//}
//
//void dfs(int row) {
//	if (row == n) {
//		cnt++;
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		queen_map[row] = i;
//
//		if (promising(row)) {
//			dfs(row + 1);
//		}
//	}
//}
//
//int main(void) {
//	cin >> n;
//	dfs(0);
//
//	cout << cnt;
//	return 0;
//}