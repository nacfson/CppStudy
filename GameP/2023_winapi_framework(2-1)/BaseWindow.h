#pragma once
class BaseWindow
{
public:
	BaseWindow(POINT _ptResolution);
	~BaseWindow();
	int			    Run(HINSTANCE _hInst, int _nCmdShow);
	ATOM                MyRegisterClass();
	void			    WindowCreate();
	void				WindowShow(int _nCmdShow);
	void				WindowUpdate();
	static LRESULT CALLBACK WndProc(HWND _hWnd, UINT _message, WPARAM _wParam, LPARAM _lParam);
	int					MessageLoop();
private:
	HWND		m_hWnd;
	HINSTANCE	m_hInst;
	POINT		m_ptResolution;
};

