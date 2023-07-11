//#include <iostream>
//#include <vector>
//#include <functional>
//
//using namespace std;
////typedef int Add(int a, int b);
//int Add(int, int);
//typedef int (FUNC_TYPE)(int, int);
////using FUNC_TYPE2 = int(int, int); //modren c++;
//
//typedef bool (ITEM_SELECTOR)(Item* _item, int _val);
//
//class Item {
//public:
//	Item()
//		:m_itemid(0)
//		, m_rarity(0)
//		, m_userid(0)
//	{}
//public:
//	void Test() {
//		cout << "Item 의 Test" << '\n';
//	}
//public:
//	int m_itemid;
//	int m_rarity;
//	int m_userid;
//};
//typedef void (Item::* TEST_FUNC)();
//
//int main() {
//	TEST_FUNC testfn;
//	testfn = &Item::Test;
//}
//
//Item* FindItem(Item _items[], int _count, ITEM_SELECTOR* _selector = IsItemId) {
//	for (int i = 0; i < _count; i++) {
//		Item* item = &_items[i];
//		/*if (item->m_itemid == _itemID) {
//			return item;
//		}*/
//		if (_selector(item,3)) return item;
//		//아이템 찾으면 리턴
//	}
//	return nullptr;
//}
//
//bool IsRarityItem(Item* _item) {
//	return _item->m_rarity >= 3;
//}
//
//bool IsItemId(Item* _item,int _itemid) {
//	return _item->m_itemid == _itemid;
//}
//
//int main(void) {
//	Item items[10] = {};
//	items[2].m_itemid = 3;
//	items[2].m_rarity = 3;
//	Item* select = FindItem(items, 10,IsItemId);
//	int a;
//	float b;
//	FUNC_TYPE* func = Add;
//	cout << Add(1, 2);
//	int ab = 0;
//	return 0;
//}
//
//int Add(int a, int b) {
//	return a + b;
//}