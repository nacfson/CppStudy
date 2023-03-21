#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
int m_count = 0;
using namespace std;

int recursion(const char* s, int l, int r) {
    m_count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int n;
    cin >> n;
    vector<string> str;
    for (int i = 0; i < n; i++)
    {
        char input[1001];
        cin >> input;
        str.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        const char* c = str[i].c_str();
        cout << isPalindrome(c) << " " << m_count << endl;
        m_count = 0;
    }
}