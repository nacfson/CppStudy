#include <iostream>
using namespace std;
class Time
{
	int hour, min, sec;
public :
	Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s }{};
	bool operator==(Time& t2)
	{
		if (hour == t2.hour && min == t2.min && sec == t2.sec)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Time& t2)
	{
		if (hour != t2.hour || min != t2.min || sec != t2.sec)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main(void)
{
	Time t1{ 1,2,3 } , t2{ 1,2,3 };
	cout.setf(cout.boolalpha);

	cout << (t1 == t2) << endl;
	cout << (t1 != t2) << endl;

	return 0;
}