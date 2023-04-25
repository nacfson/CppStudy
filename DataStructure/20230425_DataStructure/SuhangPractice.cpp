#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Swap1(int &a, int& b) {
	int temp = a;
	a = b;
	b = a;
}
void Swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(void) {
	string str = "I love c++";
	cout << str << endl;
	int pos = str.find("+");
	cout << "++이 시작되는 인덱스" << pos << endl;
	cout << str.replace(pos,2,"") << endl;
	cout << str.replace(pos,2,"#") << endl;

	vector<int> v1{ 1,3,4,5,6 };
	v1.push_back(7);
	v1.pop_back();
	cout << v1.front() << endl;
	cout << v1.back() << endl;
	cout << v1.size() << endl;
	v1.insert(v1.begin()+1,2);
	v1.erase(v1.begin()+1,v1.begin()+3);

	int arr[8] = { 0 };
	fill(arr,arr + 3,1);
	int* ptr;
	ptr = &arr[0];
	cout << ptr[2];

	return 0;
}