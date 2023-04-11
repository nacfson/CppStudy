#include <iostream>
#include "bombman.h"
#include "StartScene.h"
#include <synchapi.h>
using namespace std;

int main(void) {
	while (true) {
		AsciiArt();
		int iMenu = GameMenu();
		if(iMenu == 0) { //게임 시작
			break;
		}
		else if (iMenu == 1) { //게임 정보
			GameInfo();
		}
		else if (iMenu == 2) { //게임 종료
			cout << "게임을 종료합니다" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "\r" << 3 - i << "...";
				Sleep(1000);
			}
			return 0;

		}
	}

	return 0;
}