#include <iostream>
#include "Core.h"
using namespace std;

int main(void) {
	//GameManager �ʱ�ȭ
	//GameManager ����
	if (Core::GetInstance()->Init()) {
		cout << "Core �ʱ�ȭ ����!" << endl;
		Core::DestroyInstance();
		return 0;
	}

	Core::GetInstance()->Run();
	Core::DestroyInstance();
	return 0;
}