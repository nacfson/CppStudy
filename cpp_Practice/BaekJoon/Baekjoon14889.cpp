//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <map>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	int linkArr[20][20];
//	vector<int> memo;
//
//	int startSum = 0;
//	int linkSum = 0;
//	
//		
//	//��ŸƮ �� ��ũ �� �ΰ��� ����� �� ���� ���� ���밪���� �ٲ���
//
//	int result = 0;
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> linkArr[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			startSum += linkArr[startTeam[i]][startTeam[j]] + linkArr[startTeam[j]][startTeam[i]];
//			linkSum += linkArr[linkTeam[i]][linkTeam[j]] + linkArr[linkTeam[j]][linkTeam[i]];
//		}
//	}
//
//	cout << result;
//	return 0;
//}	