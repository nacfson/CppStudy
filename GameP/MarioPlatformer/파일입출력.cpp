#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	//파일은 쓰기, 읽기
	//std::ofstream writeFile("test2.txt"); //output file stream
	//writeFile.open("test.txt");
	//char arr[8] = "HyungJu";
	//if (writeFile.is_open()) {
	//	writeFile.write(arr,8);
	//	writeFile << "겜프" << endl;
	//	writeFile << "겜프";
	//}

	//string str;
	//for (int i = 0; i < 5; i++) {
	//	cin >> str;
	//	writeFile << str << endl;
	//}
	//writeFile.close();

	//파일 읽기 -> get
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