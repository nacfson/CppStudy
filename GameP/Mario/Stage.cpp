#include "Stage.h"
#include <iostream>
#include <fstream>
using namespace std;

Stage::Stage(){

}

Stage::~Stage(){
}

bool Stage::Init(char* fileName){
	ifstream readFile;
	if (readFile.is_open()) {
		return false;
	}
	readFile.open(fileName);
	for (int i = 0; i < HEIGHT; i++) {
		readFile.getline(map[i],WIDTH + 1); //들어갈 버퍼위치, 크기
		for (int j = 0; j < WIDTH; j++) {
			if (map[i][j] == (char)STAGE_BLOCK_TYPE::START) {
				startPoint.x = j;
				startPoint.y = i;
			}
			if (map[i][j] == (char)STAGE_BLOCK_TYPE::END) {
				endPoint.x = j;
				endPoint.y = i;
			}
		}
	}
	return false;
}

void Stage::Render(){
}
