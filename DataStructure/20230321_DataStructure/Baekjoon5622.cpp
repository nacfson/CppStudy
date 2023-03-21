#include <iostream>
using namespace std;
int ReturnDial(char a)
{
	return 0;
}
int main(void)
{
	string word;
	cin >> word;

	int sum = 0;

	for (int i = 0; i < word.size() ; i++)
	{
		sum += ReturnDial(word[i]);
	}
	cout << sum;
	return 0;
}