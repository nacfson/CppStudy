//#include <iostream>
//#include <stack>
//int main(void) {
//	std::string result;
//	std::cin >> result;
//
//	std::stack<char> brackets;
//	bool value = false;
//
//	for (int i = 0; i < result.size(); i++) {
//		char ch = result[i] ;
//
//		if (ch == '(') {
//			brackets.push('(');
//		}
//		if(ch == ')') {
//			if (brackets.empty()) {
//				value = false;
//				break;
//			}
//			char top = brackets.top();
//			brackets.pop();
//			if (top == '(') {
//				value = true;
//				continue;
//			}
//			else {
//				value = false;
//				break;
//			}
//		}
//	}
//
//	if (value) {
//		std::cout << "괄호 검사 성공";
//	}
//	else {
//		std::cout << "괄호 검사 실패";
//	}
//	return 0;
//}