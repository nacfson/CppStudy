#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> mapVec;
int vertexCnt, lineCnt, startVertex;

vector<int> dfsVec;
vector<int> bfsVec;

bool dfsVisited[1001] = {};
bool bfsVisited[1001] = {};

bool isLinked(int a, int b) {
	if (mapVec[a][b] == 1) {
		return true;
	}
	return false;
}

void dfs(int vertex) {
	dfsVec.push_back(vertex);
	dfsVisited[vertex] = true;

	for (int i = 1; i <= vertexCnt; i++) {
		if (dfsVisited[i]) continue;
		if (isLinked(vertex, i) && i != vertex) {
			dfs(i);
		}
	}
}

void bfs(int vertex) {
	queue<int> q;
	bfsVisited[vertex] = true;
	bfsVec.push_back(vertex);
	q.push(vertex);

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 1; i <= vertexCnt; i++) {
			if (bfsVisited[i]) continue;

			if (isLinked(a, i) && a != i) {
				bfsVisited[i] = true;
				q.push(i);
				bfsVec.push_back(i);
			}
		}
	}
}
int main(void) {
	cin >> vertexCnt >> lineCnt >> startVertex;

	mapVec.resize(1000, vector<int>(1000, -1));

	for (int i = 0; i < vertexCnt; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		mapVec[tmp1][tmp2] = 1;
	}

	dfs(startVertex);
	bfs(startVertex);

	for (int i = 0; i < dfsVec.size(); i++) {
		cout << dfsVec[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < bfsVec.size(); i++) {
		cout << bfsVec[i] << ' ';
	}

	return 0;
}