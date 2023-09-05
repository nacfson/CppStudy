#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	vector<int> resultVec;
	vector<int> arrVec;

	int cnt = k;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		arrVec.push_back(i + 1);
	}
	while (!arrVec.empty()) {
		idx = (idx + k - 1) % arrVec.size();
		resultVec.push_back(arrVec[idx]);
		auto iter = arrVec.begin();
		advance(iter, idx);
		arrVec.erase(iter);
	}
	cout << '<';
	for (int i = 0; i < resultVec.size(); i++) {
		if (i != resultVec.size() - 1) {
			cout << resultVec[i] << ", ";
		}
		else {
			cout << resultVec[i];
		}
	}
	cout << '>';
}