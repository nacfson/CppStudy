#include <iostream>
using namespace std;
class Apple
{
public:
	string sName;
	Apple(string name) : sName{ name } {};
	~Apple();
	void PrintName();
private:
};
int main(void)
{
	Apple *apple = new Apple("DDDD");
	apple -> PrintName();
	delete apple;
	return 0;
}

void Apple::PrintName()
{
	cout << "������" << endl;
	cout << sName << endl;
}
Apple :: ~Apple()
{
	cout << "����" << endl;
}

