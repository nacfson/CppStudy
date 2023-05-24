#pragma once

#include "Define.h"

class Core {
private:
	Core();
private:
	static Core* Instance;

public:
	static Core* GetInstance() {
		if (Instance == nullptr) {
			Instance = new Core;
		}
		return Instance;
	}
	static void DestroyInstance() {
		if (Instance) {
			delete Instance;
			Instance = nullptr;
		}
		SAFE_DELETE(Instance);
	}
public:
	bool Init();
	void Run();
	int MenuDraw();
};

