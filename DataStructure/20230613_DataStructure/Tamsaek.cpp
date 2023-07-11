#include <iostream>
#include <vector>
using namespace std;
void BinarySearch(vector<int> age);

int main(void) {
	vector<int> age;
	int min, max;
	cout << "나이의 최솟값, 최댓값 입력";
	cin >> min >> max;
	for (int i = min; i < max; i++) {
		age.push_back(i);
	}
	cout << "나이가 맞다면 YES, 더 많다면 UP, 더 적다면 DOWN을 입력하세요." << endl;
	BinarySearch(age);


	return 0;
}

void BinarySearch(vector<int> age) {
	int left = 0,right = age.size()-1;

	while (left <= right) {
		int mid = (int)((left + right) * 0.5);
		string answer;
		cout << age[mid] << "살 입니까? : ";
		cin >> answer;
		if (answer == "YES") {
			cout << "wow";
			return;
		}
		else if(answer == "DOWN") {
			right = mid - 1;
		}
		else if (answer == "UP") {
			left = mid + 1;
		}
	}
	cout << "제대로 입력하세요." << endl;
	return;
}