//#include <iostream>
//using namespace std;
//
//class Item {
//public:
//	Item()
//		:m_itemid(0)
//		, m_rarity(0)
//		, m_userid(0)
//	{}
//public :
//	void Test() {
//		cout << "Item ÀÇ Test" << '\n';
//	}
//public:
//	int m_itemid;
//	int m_rarity;
//	int m_userid;
//};
//typedef void (Item::*TEST_FUNC)();
//
//int main() {
//	TEST_FUNC testfn;
//	testfn = &Item::Test;
//
//	Item i1;
//	i1.Test();
//	(i1.*testfn)();
//
//	Item* i2 = new Item;
//	(i2->*testfn)();
//}