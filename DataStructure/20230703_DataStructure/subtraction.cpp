#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(void) {
	int n, m,i,j;
	vector<int> setN;
	vector<int> setM;

	set<int> resultVec;
	int result = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int result;
		cin >> result;
		setN.push_back(result);
	}
	for (int i = 0; i < m; i++) {
		int result;
		cin >> result;
		setM.push_back(result);
	}
	sort(setN.begin(),setN.end());
	sort(setM.begin(), setM.end());

	for (int i = 0; i < n; i++) {
		if (resultVec.find(setN[i]) == resultVec.end()) {
			resultVec.insert(setN[i]);
			result++;
		}
		else {
			result--;
		}
	}

	for (int i = 0; i < m; i++) {
		if (resultVec.find(setM[i]) == resultVec.end()) {
			resultVec.insert(setM[i]);
			result++;
		}
		else {
			result--;
		}
	}

	cout << result;
	return 0;
}