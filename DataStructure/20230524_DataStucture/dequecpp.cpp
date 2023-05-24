#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    string order, nums, num;
    int t, numsize;
    bool isError = false, isReverse = false;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        isError = isReverse = false;
        deque<int> deq;
        cin >> order >> numsize >> nums;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= '0' && nums[i] <= '9') {
                num += nums[i];
            }
            else if (nums[i] == ',' || nums[i] == ']') {
                if (!num.empty()) {
                    deq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        for (int j = 0; j < order.size(); ++j)
        {
            if (order[j] == 'R') {
                // 한 줄 완성하세요 ;
                isReverse = !isReverse;
            }
            else
            {
                if (deq.empty())
                {
                    isError = true;
                    break;
                }
                if (!isReverse)
                    deq.pop_front();
                else
                    deq.pop_back();
            }
        }

        if (isError)
            cout << "error\n";
        else if (deq.empty())
            cout << "[]\n";
        else if (!isReverse)
        {
            cout << '[' << deq.front();
            deq.pop_front();
            while (!deq.empty())
            {
                cout << ',' << deq.front();
                deq.pop_front();
            }
            cout << "]\n";
        }
        else
        {
            cout << '[' << deq.back();
            deq.pop_back();
            while (!deq.empty())
            {
                cout << ',' << deq.back();
                deq.pop_back();
            }
            cout << "]\n";
        }
    }
}