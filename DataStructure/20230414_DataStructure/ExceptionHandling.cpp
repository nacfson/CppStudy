//#include <iostream>
//using namespace std;
//int dividePizza(int slices, int persons) {
//	if (persons <= 0) {
//		throw persons;
//	}
//	if (slices <= 0) {
//		throw slices;
//	}
//	return slices / persons;
//}
//
//int main(void) {
//	int pizza_slices = 0;
//	int persons = -1;
//	int slices_per_person = 0;
//
//	cout << "피자 조각수를 입력하시오: ";
//	cin >> pizza_slices;
//	cout << "사람수를 입력하시오: ";
//	cin >> persons;
//
//	try {
//		slices_per_person = dividePizza(pizza_slices,persons);
//		cout << "한 사람당 피자는" << slices_per_person << "입니다." << endl;
//	}
//	catch(int e) {
//		slices_per_person = pizza_slices / 1;
//		cout << "사람 수는 1보다 작을 수 없습니다.";
//	}
//		
//	return 0;
//}