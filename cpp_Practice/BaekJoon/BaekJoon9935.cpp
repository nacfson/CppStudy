//#include <iostream>
//using namespace std;
//
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string value;
//	string bombValue;
//
//	cin >> value >> bombValue;
//
//	string result = "";
//	
//
//	for (int i = 0; i < value.size(); i++) {
//		result += value[i];
//		if (bombValue.back() == value[i] && i - bombValue.size() >= 0) {
//			string temp = "";
//			for (int j = bombValue.size(); j > 0; j--) {
//				temp += result[result.size() - j];
//			}
//			if (temp == bombValue) {
//				result.erase(result.size() - bombValue.size());
//			}
//		}
//	}
//
//
//	if (result == "") {
//		cout << "FRULA";
//		return 0;
//	}
//	cout << result;
//
//
//	return 0;
//}