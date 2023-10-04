//#include <iostream>
//#include <map>
//using namespace std;
//
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int n, m;
//	map<int, int> nMap;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		if (nMap.find(tmp) == nMap.end()) {
//			nMap.insert({ tmp,1 });
//		}
//		else {
//			nMap[tmp]++;
//		}
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int findVal;
//		cin >> findVal;
//		if (nMap.find(findVal) != nMap.end()) {
//			cout << nMap[findVal] << ' ';
//		}
//		else {
//			cout << '0' << ' ';
//		}
//	}
//	return 0;
//}