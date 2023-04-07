#include <iostream>
using namespace std;
class Counter
{
private :
	int value;
public :
	Counter() : value{ 0 } {};
	~Counter() {}
	int getValue() const { return value; }
	void SetValue(int x) { value = x; }

	Counter& operator++()
	{
		this->value++;
		return *this;
	}
	Counter& operator++(int) {
		this->value++;
		return *this;
	}

};
int main(void)
{
	Counter c;
	cout << "ī������ ��: " << c.getValue() << endl;
	c++;
	cout << "ī������ ��: " << c.getValue() << endl;

	return 0;
}