#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	bool visited[1000000] = {};


	for (int i = n; i <= m; i++) {
		bool result = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (visited[j] == true) continue;
			if (j % i == 0) visited[j] = true;
			
			if (i % j == 0) {
				result  = false;
				break;
			}
		}
		if (result) cout << i << endl;
	}


	return 0;
}