#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	//������ ����, �б�
	//std::ofstream writeFile("test2.txt"); //output file stream
	//writeFile.open("test.txt");
	//char arr[8] = "HyungJu";
	//if (writeFile.is_open()) {
	//	writeFile.write(arr,8);
	//	writeFile << "����" << endl;
	//	writeFile << "����";
	//}

	//string str;
	//for (int i = 0; i < 5; i++) {
	//	cin >> str;
	//	writeFile << str << endl;
	//}
	//writeFile.close();

	//���� �б� -> get
	ifstream readFile;
	readFile.open("test2.txt");

	char buf[1024];
	
	while (!readFile.eof()) {
		readFile.getline(buf, 12);
		cout << buf << endl;
	}

	string str;
	while (getline(readFile, str)) {
		cout << str << endl;
	}

	//while (!readFile.eof()) {
	//	cout << readFile.get() << endl;
	//}
} 