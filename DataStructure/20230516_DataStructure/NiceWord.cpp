//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main(void) {
//	int wordCount = 0;
//	int count;
//
//	cin >> count;
//
//	for (int j = 0; j < count; j++) {
//		stack<char> words;
//		string str;
//		cin >> str;
//		for (int i = 0; i < str.length(); i++) {
//
//			if (words.empty()) {
//				words.push(str[i]);
//			}
//			else {
//				if (words.top() == str[i]) {
//					words.pop();
//				}
//				else {
//					words.push(str[i]);
//				}
//			}
//		}
//		if (words.empty()) {
//			wordCount++;
//		}
//	}
//
//	cout << wordCount;
//	return 0;
//}