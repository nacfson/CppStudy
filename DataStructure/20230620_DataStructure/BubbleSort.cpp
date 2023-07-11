//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main(void) {
//	vector<int> vec;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string input;
//		cin >> input;
//		vec.push_back(stoi(input));
//	}
//
//	for (int i = 0; i < vec.size(); i++) {
//		for (int j = 0; j < vec.size() - i - 1; j++) {
//			if (vec[j] > vec[j + 1]){
//				int temp = vec[j];
//				vec[j] = vec[j + 1];
//				vec[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << endl;
//	}
//
//	return 0;
//}