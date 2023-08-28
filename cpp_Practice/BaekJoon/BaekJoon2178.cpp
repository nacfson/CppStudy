#include <iostream>
#include <queue>
using namespace std;
int row, col;
string board[100];
int visited[100][100];

void BFS(int x, int y) {

	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };


	queue<pair<int, int>> q;
	q.push({ 0,0 });

	visited[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || ny >= col || nx >= row) continue;

			if (visited[nx][ny] == 0 && board[nx][ny] == '1') {
				q.push({ nx,ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main(void) {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		cin >> board[i];
	}
	BFS(0, 0);

	cout << visited[row - 1][col - 1];
	return 0;
}