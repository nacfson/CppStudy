#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"

BaseWindow::BaseWindow() {}

BaseWindow::BaseWindow(POINT resolution)
{
    _hInstance = 0;
    _hWnd = 0;
    _windowResolution = resolution;
}

BaseWindow::~BaseWindow()
{

}

ATOM BaseWindow::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = BaseWindow::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInstance;
    wcex.hIcon = LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_MY2023WINAPIFRAMEWORK21));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY2023WINAPIFRAMEWORK21);
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void BaseWindow::WindowCreate()
{
    int winPosX = GetSystemMetrics(SM_CXSCREEN) * 0.5f - _windowResolution.x * 0.5f;
    int winPosY =  GetSystemMetrics(SM_CYSCREEN) * 0.5f - _windowResolution.y * 0.5f;
    
    HWND hWnd = CreateWindowW(WINDOW_CLASS_NAME, L"형주", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, _windowResolution.x, _windowResolution.y,0, nullptr, nullptr, this->_hInstance, nullptr);

    RECT rect = { winPosX,winPosY,winPosX + _windowResolution.x,winPosY + _windowResolution.y };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
    MoveWindow(hWnd, winPosX, winPosY, rect.right - rect.left, rect.bottom - rect.top, true);
}

void BaseWindow::WindowShow(int nCmdShow)
{
    ShowWindow(_hWnd, nCmdShow);
}

void BaseWindow::WindowUpdate()
{
    UpdateWindow(_hWnd);
}

int BaseWindow::Run(HINSTANCE hIsntance, int nCmdShow)
{
    this->_hInstance = _hInstance;

    this->MyRegisterClass();
    this->WindowCreate();
    this->WindowShow(nCmdShow);
    this->WindowUpdate();

    //Core Init()
    if (Core::GetInst()->Init(_hWnd,_windowResolution)) {
        MessageBox(_hWnd, L"Core 객체 초기화 실패",L"FAIL",MB_OK);
    }

    return MessageLoop();
}

LRESULT BaseWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int BaseWindow::MessageLoop()
{
    MSG msg;
    memset(&msg,0,sizeof(&msg));

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Core::GetInst()->GameLoop();
        }
    }
	return 0;
}
