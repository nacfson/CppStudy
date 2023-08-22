#define MAX_VTXS 200
#include <iostream>
#include <vector>
using namespace std;

class AdjMatGraph
{
protected:
	int size;
	vector<char> vertices;
	vector<vector<int>> adjVec;
public:
	//AdjMatGraph() { reset(); }

	AdjMatGraph(int size) {
		reset(size);
	}

	char getVertex(int i) { return vertices.at(i); }
	int getEdge(int i, int j) {
		return adjVec[i][j];
	}
	void setEdge(int i, int j, int val) {
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset(int size) {
		size = 0;
		vertices.resize(size);
		//adjVec.resize(size,vector<int>(size));
		adjVec.resize(size);
		for (int i = 0; i < size; i++) {
			adjVec[i].resize(size);
			for (int j = 0; j < size; j++) {
				setEdge(i, j, 0);
			}
		}
	}

	void insertVertex(char name) {
		if (!isFull()) {
			vertices.push_back(name);
		}
	}

	void insertEdge(int t1, int t2) {
		setEdge(t1, t2, 1);
		setEdge(t2, t1, 1);
	}
	void display() {
		cout << "  ";
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << ' ';
		}
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << ' ';
			for (int j = 0; j < size + 1; j++) {
				cout << getEdge(i, j - 1) << ' ';
			}
			cout << '\n';
		}
	}

};

int main() {
	int n, m, temp1, temp2;
	cout << "정점의 개수와 간선의 수 :";
	cin >> n >> m;
	cout << "간선의 시작정점과 끝 정점 :" << endl;

	AdjMatGraph g(MAX_VTXS);


	for (int i = 0; i < n; i++)
		g.insertVertex('A' + i);

	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		g.insertEdge(temp1, temp2);
	}
	cout << "인접 행렬로 표현한 그래프" << endl;
	g.display();
	return 0;
}