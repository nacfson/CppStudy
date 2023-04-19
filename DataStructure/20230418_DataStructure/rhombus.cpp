#include <iostream>
using namespace std;

int main(void) {
	int count;
	cin >> count;

	for (int i = 0; i < count + 1; i++) {
		for (int j = count; j >= i; j--) {
			cout << " ";
		}
		cout << "*";
		for (int k = 0; k < 4 * i; k += 2) {
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}

	for (int i = count; i > -1; i--) {
		for (int j = count; j >= i; j--) {
			cout << " ";
		}
		cout << "*";
		for (int k = count * 2; k > (count - i) * 2; k -= 1) {
			cout << " ";
		}
		cout << "*";

		cout << endl;
	}
	return 0;
}