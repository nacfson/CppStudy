#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<char> v;
	v.resize(10000);
	for (int i = 0; i < 1000; i++)
	{
		cout << v.size() << " " << v.capacity() << endl;
	}




	return 0;
}