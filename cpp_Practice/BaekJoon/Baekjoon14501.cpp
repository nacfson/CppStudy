#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class KVP
{
public:
	int day;
	int profit;
	KVP(int day, int profit) : day{ day }, profit{ profit }{};
	KVP(){}

	float GetWeight() {
		return profit / day;
	}
};

int main(void) {
	//시간 대비 최고 효율을 뽑는 사람들을 모은다.
	//그 중 시간에 알맞게 딱 맞춘다. (이게 좀 어려울 듯)
	//전체 탐색 vs 가중치 알고리즘

	int n;
	cin >> n;
	
	KVP kvpArr[15]{};
	for (int i = 0; i < n; i++) {
		int day, profit;
		cin >> day >> profit;

		KVP vp(day, profit);
		kvpArr[i] = vp;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			if (kvpArr[j].GetWeight() > kvpArr[j+1].GetWeight()) {
				KVP tmp = kvpArr[j];
				kvpArr[j] = kvpArr[j+1];
				kvpArr[j+1] = tmp;
			}
		}
	}
	

}