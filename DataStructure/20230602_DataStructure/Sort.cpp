////Selection Sort
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void) {
//	vector<int> vec;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int value;
//		cin >> value;
//
//		vec.push_back(value);
//	}
//
//
//	for (int i = 0; i < vec.size(); i++) {
//		int smallIndex = i;
//		for (int j = i; j < vec.size(); j++) {
//			if (vec[smallIndex] > vec[j]) {
//				smallIndex = j;
//			}
//		}
//		int temp = vec[i];
//		vec[i] = vec[smallIndex];
//		vec[smallIndex] = temp;
//	}
//	
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << endl;
//	}
//	return 0;
//}


//Insert Sort

#include <iostream>
using namespace std;
int main() {
	int a[100], n, tmp, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 1; i < n; i++) {
		tmp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (a[i] < a[j]) a[j + 1] = a[j];
			else break;
		}
		a[j + 1] = tmp;
	}
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}