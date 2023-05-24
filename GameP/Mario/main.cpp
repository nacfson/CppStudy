#include <iostream>
#include "Core.h"
using namespace std;

int main(void) {
	//GameManager 초기화
	//GameManager 실행
	if (Core::GetInstance()->Init()) {
		cout << "Core 초기화 실패!" << endl;
		Core::DestroyInstance();
		return 0;
	}

	Core::GetInstance()->Run();
	Core::DestroyInstance();
	return 0;
}