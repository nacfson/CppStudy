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
	int n;

	cin >> n;
	
	KVP kvpArr[15]{};
	for (int i = 0; i < n; i++) {
		int day, profit;
		cin >> day >> profit;

		KVP vp(day, profit);
		kvpArr[i] = vp;
	}
	int curProfit = 0;
	int curDay = 0;

	int maxProfit = 0;
	


	cout << maxProfit;
}