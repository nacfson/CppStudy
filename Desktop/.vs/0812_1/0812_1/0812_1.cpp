
#include <iostream>
using namespace std;
class Sell{
	int price;
	int count;
public:
	void setPrice(int value);
	void setCount(int value);
	int sell();
	void discount();
	int getPrice();
	int getCount();
};
int main()
{
	int price = 0, count = 0,num = 0;
	Sell sell;
	while (num != 6)
	{
		num = 0;
		cout << "사용할 기능을 입력하시오" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cin >> price >> count;
			sell.setPrice(price);
			break;
		case 2:
			sell.sell();
			break;
		case 3:

			break;
		case 4:
			cout << sell.getPrice();
			break;
		case 5:
			cout << sell.getCount();
			break;
		case 6:
			break;
		}
	}
}

void Sell::setPrice(int value)
{
	price = value;

}
void Sell::setCount(int vlaue)
{
	count = vlaue;
}
int Sell::sell()
{
	return price * count;
}
void Sell :: discount()
{

}
int Sell::getPrice()
{
	return price;
}
int Sell::getCount()
{
	return count;
}

