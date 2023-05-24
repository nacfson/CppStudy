#include <iostream>
#include <Windows.h>
#include "Core.h"
using namespace std;
Core* Core::Instance = nullptr;


bool Core::Init() {
	//Manager들 초기화
	// 커서 없애기

	return true;
}
void Core::Run() {
	int stage = MenuDraw();
	while (true) {








	}



}
int Core::MenuDraw() {
	cout << "1. Stage1 " << endl;
	cout << "2. Stage2 " << endl;
	cout << "3. Stage3 " << endl;
	cout << "4. Exit " << endl;
	int input;
	cin >> input;
	return input;
}

