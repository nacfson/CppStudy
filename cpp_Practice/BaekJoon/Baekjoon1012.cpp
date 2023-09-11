//#include <iostream>
//#include <queue>
//using namespace std;
//int px[4]{ -1,1,0,0 };
//int py[4]{ 0,0,-1,1 };
//
//bool visited[100][100];
//int board[100][100];
//int t, m, n, k;
//
//void DFS(int x, int y){
//	visited[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + px[i];
//		int ny = y + py[i];
//		if (visited[nx][ny] == false && board[nx][ny] == 1 && nx >= 0 && ny >= 0 && nx < m && ny < n) {
//			DFS(nx, ny);
//		}
//	}
//}
//
//int main(void) {
//	queue<int> result;
//	cin >> t;
//
//	for (int i = 0; i < t; i++) {
//		int answer = 0;
//		cin >> m >> n >> k;
//
//		fill_n(board[0], 100 * 100, 0);
//		fill_n(visited[0], 100 * 100, 0);
//
//		for (int p = 0; p  < k; p++) {
//			int tmp1, tmp2;
//			cin >> tmp1 >> tmp2;
//			board[tmp1][tmp2] = 1;
//		}
//
//		//for (int p = 0; p < m; p++) {
//		//	for (int j = 0; j < n; j++) {
//		//		if (visited[p][j] == true || board[p][j] == 0) continue;
//		//		DFS(p, j);
//		//		++answer;
//		//	}
//		//}
//
//
//		for (int j = 0; j < m; j++) {
//			for (int k = 0; k < n; k++) {
//				if (visited[j][k] == true || board[j][k] == 0) continue;
//				DFS(j, k);
//				++answer;
//			}
//		}
//		result.push(answer);
//	}
//
//	for(int i = 0; i < t; i++){
//		cout << result.front() << '\n';
//		result.pop();
//	}
//
//
//	return 0;
//}