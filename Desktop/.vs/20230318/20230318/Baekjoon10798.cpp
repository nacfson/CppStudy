#include <iostream>
#include <string>
using namespace std;

int main() {
    string words[5];
    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    string result = "";
    for (int i = 0; i < 15; i++) { // �ִ� 15���ڱ����� ó��
        for (int j = 0; j < 5; j++) {
            if (i < words[j].length()) { // ���� �ܾ i��° ���ڰ� �ִ��� Ȯ��
                result += words[j][i]; // i��° ���ڸ� ��� ���ڿ��� �߰�
            }
        }
    }

    cout << result << endl;

    return 0;
}
