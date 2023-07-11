#include <iostream>
using namespace std;

//�Լ� ��ü(Functor): �Լ�ó�� �����ϴ� ��ü.
class Functor {
public :
	void operator()(int val) {
		cout << "�Լ� ��ü" << '\n';
		this->val += val;
		cout << this->val << '\n';
	}
	void operator()(int val, int val2) {
		cout << "�Լ� ��ü" << '\n';
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