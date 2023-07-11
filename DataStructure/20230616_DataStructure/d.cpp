//#include <iostream>
//#include <map>
//using namespace std;
//bool ContainKey(map < string, int> books, string value) {
//	bool result = false;
//	
//	for (auto v : books) {
//		if (v.first == value) {
//			result = true;
//			return result;
//		}
//	}
//	return result;
//
//}
//string ReturnValue(map<string, int> books) {
//	int maxValue = 0;
//	string result = "";
//	for (auto v : books) {
//		if (maxValue < v.second) {
//			maxValue = v.second;
//			result = v.first;
//		}
//	}
//	return result;
//}
//
//int main(void) {
//	map<string, int> books;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string result;
//		cin >> result;
//		if (ContainKey(books, result)) {
//			books[result] += 1;
//		}
//		else {
//			books.emplace(result, 1);
//		}
//	}
//
//	cout << ReturnValue(books);
//	return 0;
//}