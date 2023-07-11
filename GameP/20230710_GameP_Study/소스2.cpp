#include <iostream>
using namespace std;

//함수 객체(Functor): 함수처럼 동작하는 객체.
class Functor {
public :
	void operator()(int val) {
		cout << "함수 객체" << '\n';
		this->val += val;
		cout << this->val << '\n';
	}
	void operator()(int val, int val2) {
		cout << "함수 객체" << '\n';
		this->val += val + val2;
		cout << this->val;
	}

public:
	int val = 0;
	
};

class Item {
public:
	Item()
		:m_itemid(0)
		, m_rarity(0)
		, m_userid(0)
	{}
public:
	void Upgrade(int val) {
		m_rarity += 1;
	}
public:
	int m_itemid;
	int m_rarity;
	int m_userid;
};

int main(void) {
	Functor functor;
	functor(10);
	functor(10, 10);

	return 0;
}