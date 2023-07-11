#include <iostream>
#include <vector>
#include <memory>
enum class ItemType {
	None,
	Weapon,
	Armor
};
class Item {
public:
	Item(int  itemId, int rarity, ItemType type)
		:m_itemid(itemId)
		, m_rarity(rarity)
		, m_type(type)
	{}
public:
	void Upgrade(int val) {
		m_rarity += 1;
	}
public:
	int m_itemid;
	int m_rarity;
	ItemType m_type;
};
class IsWeapon {
public:
	bool operator()(const Item& item) {
		return item.m_type == ItemType::Weapon;
	}
};
class IsArmor {
public:
	bool operator()(const Item& item) {
		return item.m_type == ItemType::Armor;
	}
};
class IsId {

public:
	IsId(int id) {
		itemID = id;
	}
	bool operator()(Item& item) {
		return itemID == item.m_itemid;
	}
	int itemID;
};


int main(void) {
	std::vector<Item> v;
	//v.push_back()
	v.push_back(Item(1, 1, ItemType::None));
	v.push_back(Item(2, 10, ItemType::Weapon));
	v.push_back(Item(3, 100, ItemType::Armor));
	Item i1(1, 1, ItemType::None);
	Item i2(1,1,ItemType::Weapon);
	i2 = i1;
	i2 = static_cast<Item&&>(i1);
	i2 = std::move(i1);

	//std::unique_ptr<Item> uptr = std::make_unique<Item>();
	//std::unique_ptr<Item> uptr2 = std::move(uptr);
	auto findlLambda = [](Item& item) {return item.m_type == ItemType::Weapon; };
	auto findArmor = [=](Item& item) {return item.m_type == ItemType::Armor; };

	auto findItem = std::find_if(v.begin(),v.end(), findlLambda);
	if (findItem != v.end()) {
		std::cout << "아이템 id는" << findItem->m_itemid << "입니다" << std::endl;
	}
	//람다: 함수 객체를 ㅕㄴ하게 만ㄷ르어주는 modern c++ 문법이다.

	//대 소 중
	auto findITem3 = std::find_if(v.begin(), v.end(), IsID(3));


	auto findItem2 = std::find_if(v.begin(), v.end(), findArmor);
	if (findItem != v.end()) {
		std::cout << "아이템 id는" << findItem->m_itemid << "입니다" << std::endl;
	}


	return 0;
}