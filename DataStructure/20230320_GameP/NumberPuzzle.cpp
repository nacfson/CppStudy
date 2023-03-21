//#include <iostream>
//#include <conio.h>
//using namespace std;
//	
//void Init(int iNumber[])
//{
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 23; i++)
//	{
//		iNumber[i] = i + 1;
//	}
//	iNumber[24] = INT_MAX;
//
//	int iTemp, idx1, idx2;
//	for (int i = 0; i < 100; i++)
//	{
//		idx1 = rand() % 24;
//		idx2 = rand() % 24;
//		iTemp = iNumber[idx1];
//		iNumber[idx1] = iNumber[idx2];
//		iNumber[idx2] = iTemp;
//	}
//}
//void RenderNumber(int iNumber[])
//{
//	cout << "===========================================" << endl;
//	cout << "|\t 숫자 퍼즐 게임\t" << endl;
//	cout << "===========================================" << endl;
//	cout << "*를 움직여서 1~24 까지 퍼즐을 맞춰보세요." << endl;
//	cout << "===========================================" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (iNumber[i * 5 + j] == INT_MAX)
//				cout << "*" << "\t";
//			else
//				cout << iNumber[i * 5 + j] << "\t";
//		}
//		cout << endl;
//	}
//}
//char Update(int iNumber[])
//{
//	cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료" << endl;
//	static int startIndex = 24;
//	char cInput = _getch();
//	switch (cInput)
//	{
//	case 'w':
//	case 'W':
//		if (startIndex > 4)
//		{
//			iNumber[startIndex] = iNumber[startIndex - 5];
//			iNumber[startIndex - 5] = INT_MAX;
//			startIndex -= 5;
//		}
//		break;
//	case 's':
//	case 'S':
//		if (startIndex < 20)
//		{
//			iNumber[startIndex] = iNumber[startIndex + 5];
//			iNumber[startIndex + 5] = INT_MAX;
//			startIndex += 5;
//		}
//		break;
//	case 'a':
//	case 'A':
//		if (startIndex % 5 != 0)
//		{
//			iNumber[startIndex] = iNumber[startIndex -1];
//			iNumber[startIndex -1] = INT_MAX;
//			startIndex --;
//		}
//		break;
//	case 'd':
//	case 'D':
//		if (startIndex % 5 != 4)
//		{
//			iNumber[startIndex] = iNumber[startIndex + 1];
//			iNumber[startIndex + 1] = INT_MAX;
//			startIndex++;
//		}
//		break;
//	}
//	return cInput;
//}
//void PuzzleCheck(int iNumber[])
//{
//	bool check = true;
//	for (int i = 0; i < 24; i++)
//	{
//		if (iNumber[i] != i + 1)
//		{
//			check = false;
//			break;
//		}
//	}
//	if (check == true)
//	{
//		cout << "다 맞췄습니다";
//		return;
//	}
//}
//int main(void)
//{
//	int iNumber[25] = {};
//	Init(iNumber);
//	while (true)
//	{
//		system("cls");
//		RenderNumber(iNumber);
//		PuzzleCheck(iNumber);
//		char cChk = Update(iNumber);
//		if (cChk == 'q' || cChk == 'Q')
//			break;
//		
//	}
//	cout << "게임을 종료합니다.";
//	//for (int i = 0; i < 25; i++)
//	//{
//	//	cout << iNumber[i] << " ";
//	//}
//	return 0;
//}