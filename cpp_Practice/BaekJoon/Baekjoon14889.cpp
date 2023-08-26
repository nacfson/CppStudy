#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int GetStats(int x,int y,int arr[20][20]) {
	if (arr[x][y] == 0 || arr[y][x] == 0) return 0;
	return arr[x][y] + arr[y][x];
}

int main(void) {
	int n;
	cin >> n;

	int linkArr[20][20];
	vector<int> memo;
	int result = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			linkArr[j][i] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int compareVal = GetStats(i, j, linkArr);
			if (compareVal == 0) continue;

			memo.push_back(compareVal);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int statVal = GetStats(i, j, linkArr);
			if (statVal == 0) continue;

			int closestVal = 99999;
			for (int i = 0; i < memo.size(); i++) {
				int compareVal = abs(statVal - memo[i]);

				if (compareVal >= 0  && compareVal <  closestVal) {
					closestVal = compareVal;
					//memo.erase(0, memo.at(i));
					//Vector에서 제거하는 것도 실행시켜주어야 함
					cout << "ClosestVal: " << closestVal;
				}
			}

			result += closestVal;
		}
	}
	cout << result;
	
	






	
	return 0;
}	