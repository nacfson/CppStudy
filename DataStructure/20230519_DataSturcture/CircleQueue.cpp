#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N, K;

	cin >> N >> K;
	list<int> circleList;
	for (int i = 1; i <= N; i++) {
		circleList.push_back(i);
	}
	list<int>::iterator target = circleList.begin();

	cout << '<';
	while (N > 0) {
		for (int i = 1; i < K; i++) {
			target++;
			if (true);
		}
		if (N == 1) {
			cout << *target;
			break;
		}
		cout << *target << ", ";
		N--;
		target = circleList.erase(target);
		if (true);
	}
	cout << ">";
	return 0;
}