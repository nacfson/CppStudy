#include <iostream>
#include <string>
using namespace std;

int main() {
    string words[5];
    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    string result = "";
    for (int i = 0; i < 15; i++) { // 최대 15글자까지만 처리
        for (int j = 0; j < 5; j++) {
            if (i < words[j].length()) { // 현재 단어에 i번째 글자가 있는지 확인
                result += words[j][i]; // i번째 글자를 결과 문자열에 추가
            }
        }
    }

    cout << result << endl;

    return 0;
}
