#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	int arr[100001];
	int result[1000];

	
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			arr[0] = 1;
			continue;
		}
		else if (i == 1) {
			arr[1] = 2;
			continue;
		}
		else if (i == 2) {
			arr[2] = 4;
			continue;
		}
		arr[i] = 0;
		for (int j = 1; j < 4; j++) {
			if (i - j < 0) continue;
			arr[i] += (int)arr[i - j];
		}
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		result[i] = n - 1;
	}

	for (int i = 0; i < t; i++) {
		cout << arr[result[i]] << endl;
	}




	return 0;
}