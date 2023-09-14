//#include <iostream>
//#include <queue>
//#include <map>
//using namespace std;
//
//int main(void) {
//	int n, k;
//	cin >> n >> k;
//
//	queue<pair<int,int>> q;
//	map<int, bool> visited;
//
//	q.push({n,0});
//	visited[n] = true;
//
//	int result = 0;
//
//	while (!q.empty()) {
//		int a = q.front().first;
//		int b = q.front().second;
//		
//		q.pop();
//
//		if (a == k) {
//			result = b;
//			break;
//		}
//
//		vector<int> nextVec = { a - 1, a + 1,a * 2 };
//
//		for (auto next : nextVec) {
//			if (visited[next] == true || next > 100000) continue;
//			visited[next] = true;
//			q.push({ next,b + 1 });
//		}
//	}
//
//	cout << result;
//	return 0;
//}
