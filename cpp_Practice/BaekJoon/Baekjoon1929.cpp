//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n, m;
//	cin >> n >> m;
//	bool visited[1000001] = {};
//
//	for (int i = 2; i <= sqrt(m); i++) {
//		if (visited[i] == true) continue;
//
//		for (int j = i * i; j <= m; j += i) {
//			visited[j] = true;
//		}
//	}
//	
//	for (int i = 2; i <= m; i++) {
//		if (!visited[i] && i >= n)
//			cout << i << "\n";
//	}
//
//	return 0;
//}