#include <iostream>
#include "bombman.h"
#include "StartScene.h"
#include <synchapi.h>
using namespace std;

int main(void) {
	while (true) {
		AsciiArt();
		int iMenu = GameMenu();
		if(iMenu == 0) { //���� ����
			break;
		}
		else if (iMenu == 1) { //���� ����
			GameInfo();
		}
		else if (iMenu == 2) { //���� ����
			cout << "������ �����մϴ�" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "\r" << 3 - i << "...";
				Sleep(1000);
			}
			return 0;

		}
	}

	return 0;
}