#include <iostream>
using namespace std;
class Book
{
public:
	Book(string name, int price) :_name{ name }, _price{ price }{};
	void print();
private :
	string _name;
	int _price;
};
int main(void)
{
	Book books[2] = {

		Book("어서와 c++",25000),
		Book("어서와 C",22000),
	};
	cout << "소장하고 있는책 정보" << endl;
	cout << "====================" << endl;
	for (Book& b : books)
	{
		b.print();
	}
	cout << "======================" << endl;
	return 0;
}
void Book::print()
{
	cout << "제목: " << _name << '\t' << "가격: " << _price << endl;
}