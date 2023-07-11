#include <iostream>
#include <vector>
using namespace std;
void BinarySearch(vector<int> age);

int main(void) {
	vector<int> age;
	int min, max;
	cout << "������ �ּڰ�, �ִ� �Է�";
	cin >> min >> max;
	for (int i = min; i < max; i++) {
		age.push_back(i);
	}
	cout << "���̰� �´ٸ� YES, �� ���ٸ� UP, �� ���ٸ� DOWN�� �Է��ϼ���." << endl;
	BinarySearch(age);


	return 0;
}

void BinarySearch(vector<int> age) {
	int left = 0,right = age.size()-1;

	while (left <= right) {
		int mid = (int)((left + right) * 0.5);
		string answer;
		cout << age[mid] << "�� �Դϱ�? : ";
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
	cout << "����� �Է��ϼ���." << endl;
	return;
}