#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str = "When in Rome, do as the Romans.";
	string personalID = "\0";

	cout << str.find("Rome") << endl;
	
	cout << "주민등록번호를 입력하시오 : ";
	cin >> personalID;
	personalID.erase(personalID.find("-"), 1);
	cout << personalID;

	string hamming1;
	string hamming2;
	int hammingCount = 0;

	cin >> hamming1;
	cin >> hamming2;

	for (int i = 0; i < hamming1.size(); i++)
	{
		if (hamming1[i] == hamming2[i])
		{
			hammingCount++;
		}
	}
	cout << hammingCount;


	return 0;
}
