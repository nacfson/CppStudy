#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr){
    queue<int> sol;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        if (sol.empty()) {
            sol.push(arr[i]);
        }
        else {
            bool value = false;
            for (int k = 0; k <= sol.size(); k++) {
                if(sol.front() + k != arr[i]){
                    value = true;
                }
                else {
                    value = false;
                    break;
                }
            }
            if (value) {
                sol.push(arr[i]);
            }
        }
    }

    for (int i = 0; i <= sol.size(); i++) {
        result.push_back(sol.front());
        sol.pop();
    }
    return result;
}

int main(void) {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(5);

    arr = solution(arr);
    for(int i = 0; i< arr.size(); i++){
        cout << arr[i];
    }

    return 0;
}
