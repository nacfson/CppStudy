#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int GetStats(int x,int y,int arr[20][20]) {
	if (arr[x][y] == 0 || arr[y][x] == 0) return 0;
	return arr[x][y] + arr[y][x];
}

int main(void) {
	int n;
	cin >> n;

	int linkArr[20][20];
	//vector<int> memo;

	map<int, int> memo;
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

			if (memo.find(compareVal) != memo.end()) {
				memo[compareVal] += 1;
			}
			else {
				memo.insert(std::make_pair(compareVal, 1));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int statVal = GetStats(i, j, linkArr);
			if (statVal == 0) continue;

			int closestVal = 99999;
			for (auto it = memo.begin(); it != memo.end();) {
				int compareVal = abs(statVal - it->first);

				if (compareVal >= 0 && compareVal < closestVal) {
					closestVal = compareVal;

					if (it->second >= 1) {
						memo[it->first] -= 1;
					}
					else {
						it = memo.erase(it);
					}
					//Vector에서 제거하는 것도 실행시켜주어야 함
					///cout << "ClosestVal: " << closestVal;
				}
				else {
					it++;
				}
			}
			result += closestVal;
		}
	}
	cout << result;
	
	






	
	return 0;
}	