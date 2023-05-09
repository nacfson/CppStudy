#include <iostream>
#include <stack>
using namespace std;
int ReturnWeight(char ch) {
	switch (ch) {
	case '(': {
		return 0;
		break;
	}
	case '+': {
		return 1;
		break;
	}
	case '-': {
		return 1;
		break;
	}
	case '*': {
		return 2;
		break;
	}
	case '/': {
		return 2;
		break;
	}
	case ')': {
		return 3;
		break;
	}
	default:
		return -1;
		break;
	}
}

int main(void) {
	string input;
	cin >> input;

	stack<char> results;
	string postfix;
	for (int i = 0; i < input.size(); i++) {
		//피연산자
		if (ReturnWeight(input[i]) == -1) {
			cout << input[i];
			continue;
		}

		if (results.empty()) {
			results.push(input[i]);
		}
		else if (ReturnWeight(results.top()) < ReturnWeight(input[i])) {
			results.push(input[i]);
		}
		else {
			int size = results.size();
			while (!results.empty()) {
				postfix += results.top();
				results.pop();
				cout << postfix;
				postfix = "";
			}
			//cout << input[i];
		}
		//연산자
	}
	while (!results.empty()) {
		cout << results.top();
		results.pop();
	}
	//A + B * C - D / E

	return 0;
}