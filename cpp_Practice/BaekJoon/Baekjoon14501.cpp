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

	int maxProfit = 0;
	int curProfit = 0;


	for (int i = 0; i < n; i++) {
		int day = i;
		while (day < n) {
			int tmpMaxPro = 0;
			int tmpMaxDay = 0;

			for (int j = day; j < n; j++) {
				int plusDay = kvpArr[j].day;
				int plusProfit = kvpArr[j].profit;

				if (day + plusDay < n) {
					if (plusProfit > tmpMaxPro) {
						tmpMaxDay = plusDay;
						tmpMaxPro = plusProfit;
					}
				}
			}

			curProfit += tmpMaxPro;
			day += tmpMaxDay;

		}
		if (maxProfit < curProfit) {
			maxProfit = curProfit;
		}

		curProfit = 0;
	}

	cout << maxProfit;
}
	


