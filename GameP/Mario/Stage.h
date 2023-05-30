#pragma once
#include "Define.h"
class Stage
{
public :
	Stage();
	~Stage();
private :
	char map[HEIGHT][WIDTH];
	POINT startPoint;
	POINT endPoint;

public:
	POINT GetStart() { return startPoint; }
	POINT GetEnd() { return endPoint; }
	char GetBlock(int x, int y) {
		return map[y][x];
	}
public : 
	bool Init(char* fileName);
	void Render();

	
};

