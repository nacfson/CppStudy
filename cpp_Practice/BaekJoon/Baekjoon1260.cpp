#include <iostream>
#include <set>
#include <queue>
using namespace std;
int verCnt, lineCnt;
set<pair<int, int>> linkedSet;
bool dfsVisited[1000] = {};
bool bfsVisited[1000] = {};

bool isLinked(int ver1,int ver2) {
	return linkedSet.find({ ver1,ver2 }) != linkedSet.end() || linkedSet.find({ ver2,ver1 }) != linkedSet.end();
}

void dfs(int startVer) {
	dfsVisited[startVer] = true;
	cout << startVer << ' ';
	for (int i = 1; i <= verCnt; i++) {
		if (dfsVisited[i]) continue;

		if (isLinked(startVer,i)) {
			dfs(i);
		}
	}

}
void bfs(int startVer) {
	queue<int> q;

	bfsVisited[startVer] = true;
	q.push(startVer);
	cout << startVer << ' ';
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 1; i <= verCnt; i++) {
			if (bfsVisited[i]) continue;

			if (isLinked(a, i)) {
				cout << i << ' ';
				bfsVisited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void) {
	int startVer;

	cin >> verCnt >> lineCnt >> startVer;

	for (int i = 0; i < lineCnt; i++) {
		int tmp1, tmp2;
		cin >> tmp1>> tmp2;
		linkedSet.insert({ tmp1,tmp2 });
	}

	dfs(startVer);
	cout << '\n';
	bfs(startVer);

	return 0;
}