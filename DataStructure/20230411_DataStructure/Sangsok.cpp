#include <iostream>
using namespace std;
class CParent {
public :
	void Func() {
		cout << "CParent :: Func" << endl;
	}
};
class CTest : public CParent {
public :
	void Func() {
		cout << "CTest :: Func" << endl;
	}
};
int main(void) {
	CTest t;
	t.Func();
	t.CParent::Func();
	return 0;
}