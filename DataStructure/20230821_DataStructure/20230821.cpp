//#define MAX_VTXS 200
//#include <iostream>
//using namespace std;
//
//class AdjMatGraph
//{
//protected:
//	int size;
//	char vertices[MAX_VTXS];
//	int adj[MAX_VTXS][MAX_VTXS];
//public:
//	AdjMatGraph() { reset(); }
//	
//	char getVertex(int i) { return vertices[i]; }
//	int getEdge(int i, int j) {
//		return adj[i][j];
//	}
//	void setEdge(int i, int j, int val) {
//		adj[i][j] = val;
//	}
//	bool isEmpty() { return size == 0; }
//	bool isFull() { return size >= MAX_VTXS; }
//	void reset(){
//		size = 0;
//		for (int i = 0; i < MAX_VTXS; i++)
//			for (int j = 0; j < MAX_VTXS; j++)
//				setEdge(i, j, 0);
//	}
//
//	void insertVertex(char name) {
//		if (!isFull()){
//			vertices[size++] = name;
//		}
//	}
//
//	void insertEdge(int t1,int t2) {
//		setEdge(t1, t2, 1);
//		setEdge(t2, t1, 1);
//	}
//	void display() {
//		cout << "  ";
//		for (int i = 0; i < size; i++) {
//			cout << vertices[i] << ' ';
//		}
//		cout << endl;
//		for (int i = 0; i < size; i++) {
//			cout << getVertex(i) << ' ';
//			for (int j = 0; j < size + 1; j++) {
//				cout << getEdge(i, j - 1) << ' ';
//			}
//			cout << '\n';
//		}
//	}
//
//};
//
//int main() {
//	int n, m, temp1, temp2;
//	cout << "정점의 개수와 간선의 수 :";
//	cin >> n >> m;
//	cout << "간선의 시작정점과 끝 정점 :" << endl;
//
//	AdjMatGraph g;
//
//
//	for (int i = 0; i < n; i++)
//		g.insertVertex('A' + i);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp1 >> temp2;
//		g.insertEdge(temp1,
//			temp2);
//	}
//	cout << "인접 행렬로 표현한 그래프" << endl;
//	g.display();
//	return 0;
//}