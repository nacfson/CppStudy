#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

void Shuffle(int arr[]) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		int randValue = rand() % 20;
		int rand2Value = rand() % 20;
		int temp = arr[randValue];
		arr[randValue] = arr[rand2Value];
		arr[rand2Value] = temp;
	}
}

int GetAverage(int arr[]) {
	int average = 0;
	for (int i = 0; i < 5; i++) {
		average += arr[i];
	}
	return average / 5;
}


int main(void) {
	cout << "GGM 카드게임" << endl;
	Sleep(1000);
	cout << "게임설명: 상대방의 카드를 총으로 쏘고, 평균값을 낮춰 게임에서 승리하세요." << endl;
	Sleep(1000);
	cout << "게임을 시작하려면 아무키나 누르세요" << endl;
	Sleep(1000);

	//_setmode(_fileno(stdout), _O_U16TEXT);
	int faze = 1;
	int round = 0;

	int enemyAverage = 0;
	int playerAverage = 0;

	int playerLife = 3;
	int enemyLife = 3;

	int shuffleArr[20];

	int playerArr[5];
	int enemyArr[5];


	for (int i = 0; i < 20; i++) {
		shuffleArr[i] = i + 1;
	}
	Shuffle(shuffleArr);

	for (int i = 0; i < 5; i++) {
		playerArr[i] = shuffleArr[i];
	}
	Shuffle(shuffleArr);
	for (int i = 0; i < 5; i++) {
		enemyArr[i] = shuffleArr[i];
	}
	if (_getch()) {
		while (true) {
			int playerValue = GetAverage(playerArr);
			int enemyValue = GetAverage(enemyArr);
			round++;
			cout << "-------";
			cout << "페이즈: " << faze;
			cout << "-------" << endl;
			cout << "-------";
			cout << "라운드: " << round;
			cout << "-------" << endl;
			cout << "Player 체력: " << playerLife << endl;
			cout << "Player 평균: " << playerValue << endl;
			for (int i = 0; i < 5; i++) {
				cout << playerArr[i] << " ";
			}
			Sleep(500);
			cout << endl;
			cout << "Enemy 체력: " << enemyLife << endl;
			cout << "Enemy 평균: " << enemyValue << endl;
			for (int i = 0; i < 5; i++) {
				cout << enemyArr[i] << " ";
			}
			Sleep(500);
			cout << endl;

			int value = 0;
			cout << "--------------------";
			cout << "공격 1, 스킵 2";
			cout << "--------------------" << endl;
			cin >> value;

			int cardNum;
			if (value == 1) {
				cout << "없앨 카드의 번호를 입력하세요." << endl;
				cin >> cardNum;

				if (cardNum > 0 && cardNum <= 5) {
					enemyArr[cardNum - 1] = 0;
				}
				else {
					cout << "잘못된 값을 입력하였습니다" << endl;
					cout << "라운드를 스킵하겠습니다." << endl;
					Sleep(1000);
					system("cls");

					continue;
				}

				int value = rand() % 5;
				while (playerArr[value] == 0) {
					value = rand() % 5;
					playerArr[value] = 0;
				}
			}
			else if (value == 2) {
				cout << "라운드를 스킵합니다." << endl;
				Sleep(1000);
				system("cls");

				continue;
			}
			else {
				cout << "잘못된 값을 입력하였습니다." << endl;
				cout << "라운드를 스킵합니다." << endl;
				Sleep(1000);
				system("cls");

				continue;
			}

			for (int i = 1; i <= 3; i++) {
				cout << 4 - i << "..." << '\r';
				Sleep(1000);
			}
			if (round == 3) {
				if (playerAverage > enemyAverage) {
					playerLife--;
					round = 0;
					faze++;
				}
				else {
					enemyLife--;
					round = 0;
					faze++;
				}
			}
			system("cls");
		}
	}


	return 0;
}