#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool wordLength(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}
int main(void) {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<string> inputVec;
	set<string> result;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		inputVec.push_back(tmp);
	}

	sort(inputVec.begin(), inputVec.end(), wordLength);

	for (int i = 0; i < inputVec.size(); i++) {
		if (result.find(inputVec[i]) != result.end()) continue;
		cout << inputVec[i] << '\n';
		result.insert(inputVec[i]);
	}
	return 0;
}