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
	cout << "GGM ī�����" << endl;
	Sleep(1000);
	cout << "���Ӽ���: ������ ī�带 ������ ���, ��հ��� ���� ���ӿ��� �¸��ϼ���." << endl;
	Sleep(1000);
	cout << "������ �����Ϸ��� �ƹ�Ű�� ��������" << endl;
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
			cout << "������: " << faze;
			cout << "-------" << endl;
			cout << "-------";
			cout << "����: " << round;
			cout << "-------" << endl;
			cout << "Player ü��: " << playerLife << endl;
			cout << "Player ���: " << playerValue << endl;
			for (int i = 0; i < 5; i++) {
				cout << playerArr[i] << " ";
			}
			Sleep(500);
			cout << endl;
			cout << "Enemy ü��: " << enemyLife << endl;
			cout << "Enemy ���: " << enemyValue << endl;
			for (int i = 0; i < 5; i++) {
				cout << enemyArr[i] << " ";
			}
			Sleep(500);
			cout << endl;

			int value = 0;
			cout << "--------------------";
			cout << "���� 1, ��ŵ 2";
			cout << "--------------------" << endl;
			cin >> value;

			int cardNum;
			if (value == 1) {
				cout << "���� ī���� ��ȣ�� �Է��ϼ���." << endl;
				cin >> cardNum;

				if (cardNum > 0 && cardNum <= 5) {
					enemyArr[cardNum - 1] = 0;
				}
				else {
					cout << "�߸��� ���� �Է��Ͽ����ϴ�" << endl;
					cout << "���带 ��ŵ�ϰڽ��ϴ�." << endl;
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
				cout << "���带 ��ŵ�մϴ�." << endl;
				Sleep(1000);
				system("cls");

				continue;
			}
			else {
				cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
				cout << "���带 ��ŵ�մϴ�." << endl;
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