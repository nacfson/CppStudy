#include <iostream>
using namespace std;
#include <string>
//void Swap(int& x, int& y)
//{
//	int tmp;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
/*void Add(int* x, int* y)
{
	int a;
	cin >> a;
	*x += a;
	*y += a;


}*/
struct person {
	string name;
	int age;
	float kg;
	float height;

};

int main()
{
	/*int memberCount;
	cout << "몇 명의 시험 점수를 입력하시겠습니까?";
	cin >> memberCount;
	cout << memberCount << " 명 분의 점수를 입력하시오.\n";
	int* arr = new int[memberCount];
	for (int i = 0; i < memberCount; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= memberCount; i++)
	{
		cout << i << "번째 사람의 점수는" << arr[i - 1] << "입니다" <<endl;
	}
	delete []arr;*/
	/*int x = 1;
	int y = 3;

	cout << x << y << endl;
	Swap(x, y);
	cout << x << y << endl;*/
	
	/*int x = 80;
	int y= 85;
	cout << x << " " << y << endl;
	Add(&x, &y);
	cout << x << " " << y;*/



	person person1;
	person person2;
	cout << "회원1의 이름, 나이, 몸무게, 키를 띄워쓰기로 구분하여 입력하시오" << endl;
	cin >>person1.name>> person1.age >> person1.kg >> person1.height;
	cout << "회원2의 이름, 나이, 몸무게, 키를 띄워쓰기로 구분하여 입력하시오" << endl;
	cin >>person2.name >> person2.age >> person2.kg >> person2.height;

	cout << "이름은 " << person1.name << " 나이는 " << person1.age << " 몸무게는 " << person1.kg << " 키는 " << person1.height << endl;
	cout << "이름은 " << person2.name <<  " 나이는 " << person2.age << " 몸무게는 " << person2.kg << " 키는 " << person2.height;


	return 0;
}

