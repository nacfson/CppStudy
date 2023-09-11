#include <iostream>
#include <vector>
using namespace std;
class Tree
{
public:
	int root, idx;
	int arr[3];
	Tree(int root, int idx)
	{
		this->root = root;
		this->idx = idx;
		for (int i = 0; i < 3; i++) {
			arr[i] = root;
		}
	}
	Tree* MakeTree()
	{
		arr[0] *= 2;
		arr[1] += 1;
		arr[2] -= 1;
		return this;
	}

	int MatchValue(int value) {
		for (int i = 0; i < 3; i++) {
			if (arr[i] == value) return idx;
		}
		return -1;
	}
};

int main(void) {
	int n, m;
	int idx = 0;
	cin >> n >> m;

	vector<Tree> tmpTrees;
	vector<Tree> trees;

	Tree tree(1, idx);
	trees.push_back(tree);

	int result;
	int out = false;
	while (!out) {
		tmpTrees = trees;

		for (auto t : trees) {
			result = t.MatchValue(m);
			if (result != -1) {
				cout << result;
				out = true;
				break;
			}
		}

		trees.clear();
		for (auto t : tmpTrees) {
			Tree* tmp = t.MakeTree();
			for (int i = 0; i < 3; i++) {
				Tree tre(tmp->arr[i], idx);
				trees.push_back(tre);
			}
		}
		tmpTrees.clear();
		idx++;
	}
	return 0;
}