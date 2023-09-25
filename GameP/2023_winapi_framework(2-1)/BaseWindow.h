#pragma once
class BaseWindow
{
public:
	BaseWindow();
	BaseWindow(POINT resolution);
	~BaseWindow();
	ATOM                MyRegisterClass();
	void				WindowCreate();
	void				WindowShow(int nCmdShow);
	void				WindowUpdate();
	int					Run(HINSTANCE hIsntance,int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int					MessageLoop();

private:
	HWND		_hWnd;
	HINSTANCE	_hInstance;
	
	POINT _windowResolution;


};

