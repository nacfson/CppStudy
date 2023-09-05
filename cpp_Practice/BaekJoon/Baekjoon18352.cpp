//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//	int n,m,k,x;
//	
//	vector<vector<int>> adj;
//	queue<int> q;
//	vector<int> visited;
//	vector<int> answer;
//
//	cin >> n >> m >> k >> x;
//	visited.resize(n + 1,-1);
//
//	adj.resize(n + 1);
//	q.push(x);
//	visited[x] = 0;
//
//	for (int i = 0; i < m; i++) {
//		int tmp1, tmp2;
//		cin >> tmp1 >> tmp2;
//		adj[tmp1].push_back(tmp2);
//	}
//
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//
//		for (int i = 0; i < adj[now].size(); i++) {
//			int a = adj[now][i];
//			if (visited[a] >= 0) continue;
//			q.push(a);
//			visited[a] = visited[now] + 1;
//
//			if (visited[a] == k) {
//				answer.push_back(a);
//			}
//		}
//	}
//
//	if (answer.empty()) {
//		cout << -1;
//	}
//	else {
//		sort(answer.begin(), answer.end());
//		for (int i = 0; i < answer.size(); i++) {
//			cout << answer[i] << '\n';
//		}
//	}
//	return 0;
//}