#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int linkArr[20][20];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			linkArr[j][i] = tmp;
		}
	}





	
	return 0;
}	