
#include <iostream>
#include <string>
using namespace std;

//void Score(int score)
//{
//	char str;
//	switch (int(score/10))
//	{
//		case 10:
//		case 9:
//			str = 'A';
//			break;
//		case 8:
//			str = 'B';
//			break;
//		case 7:
//			str = 'C';
//
//			break;
//		case 6:
//			str = 'D';
//			break;
//		default:
//			str = 'E';
//			break;
//		
//	}
//	cout << str;
//}

int main()
{
	//1. score
	//int score;
	//cin >> score;
	//Score(score);


	/*int n,j,i = 0;
	//int count = 0;


	cout << "소수를 구할 최대 숫자를 입력하시오 : ";
	cin >> n;
	

	for (i = 2; i <= n; i++)
	{
		for (j =2; j <= i;j++)
		{
			if (i % j == 0) break;
		}

		if (j == i)
		{
			cout << j << " ";
			count++;
		}
	}

	cout <<"\n 2부터 " << i - 1 << "개 사이의 소수 개수는 " << count << "개 입니다.";*/

	/*int i, j;
	int h,temp;
	cin >> h;
	temp = h;

	for (i = 1; i <= h; i++)
	{
		for (j = temp - 1; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = 1; k <= i * 2; k += 2)
		{
			cout << k;
		}
		for (int l = i * 2 -3; l > 0 ; l -= 2)
		{
			cout << l;
		}
		
		temp--;
		cout << endl;
	}*/

	/*char code[14];
	cin >> code;
	bool nineteenC;
	if (code[6] == '1' || '3')
	{
		cout << "남자입니다.";

	}
	else if(code[6] == '2'||'4')
	{
		cout << "여자입니다.";
	}

	if (code[6] == '1' && '2') {
		nineteenC = true;
	}
	else if(code[6] == '3' && '4')
	{
		nineteenC = false;
	}

	if (nineteenC == true)
	{
		cout << 19 << code[0] - 48 << code[1] - 48;
	}
	else 
	{
		cout << 20 << code[0] - 48 << code[1] - 48;
	}*/





}



