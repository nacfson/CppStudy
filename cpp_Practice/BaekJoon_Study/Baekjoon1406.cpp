//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main() {
//    string initial;
//    cin >> initial;
//
//    stack<char> leftStack, rightStack;
//
//    for (char c : initial) {
//        leftStack.push(c);
//    }
//
//    int numCommands;
//    cin >> numCommands;
//    cin.ignore(); // ���� ���� ����
//
//    while (numCommands--) {
//        string command;
//        getline(cin, command);
//
//        if (command[0] == 'P') {
//            char c = command[2];
//            leftStack.push(c);
//        }
//        else if (command[0] == 'L' && !leftStack.empty()) {
//            char c = leftStack.top();
//            leftStack.pop();
//            rightStack.push(c);
//        }
//        else if (command[0] == 'D' && !rightStack.empty()) {
//            char c = rightStack.top();
//            rightStack.pop();
//            leftStack.push(c);
//        }
//        else if (command[0] == 'B' && !leftStack.empty()) {
//            leftStack.pop();
//        }
//    }
//
//    // ���ÿ� ����� ���ڿ��� ���
//    while (!leftStack.empty()) {
//        rightStack.push(leftStack.top());
//        leftStack.pop();
//    }
//
//    while (!rightStack.empty()) {
//        cout << rightStack.top();
//        rightStack.pop();
//    }
//
//    return 0;
//}
