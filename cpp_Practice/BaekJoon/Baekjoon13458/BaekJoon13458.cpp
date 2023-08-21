#include <iostream>
using namespace std;

int CalculateMaxCnt(int candidateCnt,int aMonitorCnt, int bMonitorCnt) {

	if (candidateCnt < aMonitorCnt)
	{
		return 1;
	}
	int result = 1;
	candidateCnt -= aMonitorCnt;
	

	result += static_cast<int>(candidateCnt / bMonitorCnt);
	if (candidateCnt % bMonitorCnt != 0)
	{
		result += 1;
	}
	return result;
}

int main(void) {
	int examRoomCnt;
	int candidateArr[100000];

	int maxMonitorCntA;
	int maxMonitorCntB;


	cin >> examRoomCnt;

	for (int i = 0; i < examRoomCnt; i++)
	{
		int tmp;
		cin >> tmp;
		candidateArr[i] = tmp;
	}

	cin >> maxMonitorCntA >> maxMonitorCntB;
	
	long long result = 0;
	for (int i = 0; i < examRoomCnt; i++)
	{
		result += CalculateMaxCnt(candidateArr[i],maxMonitorCntA,maxMonitorCntB);
	}
	cout << result;

	return 0;
}