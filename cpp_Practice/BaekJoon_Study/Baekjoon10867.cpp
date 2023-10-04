//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//bool findValInVec(const vector<int> vec,int matchVal) {
//	for (int i = 0; i < vec.size(); i++) {
//		if (vec[i] == matchVal) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int main(void) {
//	int n,input;
//	cin >> n;
//	vector<int> inputVec;
//	
//	for (int i = 0; i < n; i++) {
//		cin >> input;
//		if (findValInVec(inputVec, input) == false) {
//			inputVec.push_back(input);
//		}
//	}
//	sort(inputVec.begin(), inputVec.end());
//	for (int i = 0; i < inputVec.size(); i++) {
//		cout << inputVec[i] << ' ';
//	}
//	return 0;
//}