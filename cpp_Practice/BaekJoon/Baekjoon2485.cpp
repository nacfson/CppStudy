#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    vector<int> gaps;
    for (int i = 1; i < n; ++i) {
        gaps.push_back(positions[i] - positions[i - 1]);
    }

    int tempGcd = gaps[0];
    for (int i = 1; i < gaps.size(); ++i) {
        tempGcd = gcd(tempGcd, gaps[i]);
    }

    int trees = 0;
    for (int i = 1; i < n; ++i) {
        trees += (positions[i] - positions[i - 1]) / tempGcd - 1;
    }

    cout << trees << endl;

    return 0;
}
