#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	vector<int> numbers;
	cout << "������ ����";
	cin >> n;


	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		numbers.push_back(value);
	}




	return 0;
}