#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> search;

	int left = 0;
	int right;
	int first;
	int end;

	int key;
	cin >> first >> end >> key;

	for (int i = first; i <= end; i++) {
		search.push_back(i);
	}

	right = search.size() - 1;


	while (left < right) {
		int mid = (int)((search[left] + search[right]) * 0.5f);
		if (mid == key) {
			cout << "pass" << endl;
			break;
		}
		else {
			if (mid < key) {
				left = mid + 1;
				continue;
			}
			else {
				right = mid - 1;
				continue;
			}
		}
	}




	return 0;
}