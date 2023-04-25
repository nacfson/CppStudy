#include <iostream>
using namespace std;

int main(void) {
	int arr[5];
	int *pointer = arr;
	cout << &pointer << endl;
	cout << &arr[0] << endl;
	return 0;
}