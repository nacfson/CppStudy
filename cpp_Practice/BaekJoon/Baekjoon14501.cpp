////#include <iostream>
////#include <queue>
////#include <string>
////#include <algorithm>
////
////using namespace std;
////class KVP
////{
////public:
////	int day;
////	int profit;
////	KVP(int day, int profit) : day{ day }, profit{ profit }{};
////	KVP() {}
////};
////
////int GetMaxProfit(int idx,int n, KVP kvpArr[15])
////{
////	if (idx >= n) {
////		return 0;
////	}
////
////	int profitNext = GetMaxProfit(idx + 1 , n ,kvpArr);
////	int profit = 0;
////
////	if (idx + kvpArr[idx].day <= n) {
////		profit = kvpArr[idx].profit + GetMaxProfit(idx + kvpArr[idx].day,n,kvpArr);
////	}
////	return max(profitNext, profit);
////}
////
////int main(void) {
////	int n;
////
////	cin >> n;
////
////	KVP kvpArr[15]{};
////	for (int i = 0; i < n; i++) {
////		int day, profit;
////		cin >> day >> profit;
////
////		KVP vp(day, profit);
////		kvpArr[i] = vp;
////	}
////
////	
////
////	cout << GetMaxProfit(0,n,kvpArr);
////}
//
//#include<iostream>
//#include<vector>
//using namespace std;
////vector<pair<int, int>> v;
//vector<int> vect;
//vector<int> vecp;
//int memo[16];
//int n, maxmoney;
//int main()
//{
//    // === input ===
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int t, p;
//        cin >> t >> p;
//        vect.push_back(t);
//        vecp.push_back(p);
//    }
//
//    // ���⿡ �ٽ��� �ڿ������� Ȯ�����ϴ°ž�.
//    for (int i = n - 1; i >= 0; i--)
//    {
//        // ��ȭ��...
//        // �ȳѾ�� ���� �Ѵٴ°��ݾ�.
//        int time = vect[i] + i;
//        if (time <= n)
//        {
//            // time = 6(4+2) -> 4(3+1) ->
//            // 3(2+1) -> 6(1+5 => x)
//            // 3(0+3 => x) 
//            // �޸��忡 �־�ߵ�.
//            // max�� ū �� ��.
//            // ������ �ִ� �޸�..
//            // 3���� 1�̻� �۾ƾ��Ѵ�?
//            memo[i] = max(vecp[i] + memo[time], maxmoney);
//            maxmoney = memo[i];
//            //memo[i] = vecp[i] + memo[time];
//        }
//        // �Ѿ��
//        else
//        {
//            memo[i] = maxmoney;
//        }
//
//        // �޸��忡 ���� �ִ� ���� ����Ѵ�.
//    }
//
//
//    // === output === 
//    cout << maxmoney;
//
//}