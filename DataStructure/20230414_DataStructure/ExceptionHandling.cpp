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
//	cout << "���� �������� �Է��Ͻÿ�: ";
//	cin >> pizza_slices;
//	cout << "������� �Է��Ͻÿ�: ";
//	cin >> persons;
//
//	try {
//		slices_per_person = dividePizza(pizza_slices,persons);
//		cout << "�� ����� ���ڴ�" << slices_per_person << "�Դϴ�." << endl;
//	}
//	catch(int e) {
//		slices_per_person = pizza_slices / 1;
//		cout << "��� ���� 1���� ���� �� �����ϴ�.";
//	}
//		
//	return 0;
//}