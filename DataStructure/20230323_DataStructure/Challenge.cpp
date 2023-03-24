#include <iostream>
using namespace std;

class Character
{
public:
	Character(int x, int y, int hp) : _x{ x }, _y{ y },_hp{ hp }{};
	void print();
	void setX(int i);
private:
	int _x;
	int _y;
	int _hp;
};
int main(void)
{
	cout << "Ä³¸¯ÅÍ #1" << endl;
	Character a(0, 0, 100);
	for(int i= 0 ;i< 100; i+= 10)
	{
		a.setX(i);
		a.print();
	}
	return 0;
}

void Character::print()
{
	cout << "x: " << _x << " y: " << _y << " hp: " << _hp << endl;
}
void Character::setX(int i)
{
	_x = i;
}