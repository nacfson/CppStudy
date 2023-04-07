#include <iostream>
using namespace std;
class Test {
public:
	static int i;
	//print();
};
int Test::i = 0;
int main(void){
	cout << Test::i;
	return 0;
}