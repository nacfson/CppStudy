// 20230821_Gamep.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "20230821_Gamep.h"
#include <string>
#include <time.h>
using namespace std;


#define MAX_LOADSTRING 100
#define PROGRAM_TITLE L"형주의 윈도우"
#define WINSIZEX = 1280
#define WINSIZEY = 720

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING] = PROGRAM_TITLE;  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

POINT ptObjPos = { 500, 500 };
POINT ptObjScale = { 100,100 };


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance, //가상 메모리
	_In_ LPWSTR    lpCmdLine, //안 씀 cmd에서 쓰는거 -e
	_In_ int       nCmdShow) //안 씀
{
	UNREFERENCED_PARAMETER(hPrevInstance); //별의미 없음(주석)
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY20230821GAMEP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	srand((unsigned int)time(nullptr));

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY20230821GAMEP));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		//if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		//{ 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		//}
	}

	return (int)msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	//wcex.style          = 1280 | 720;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	//wcex.hbrBackground = (HBRUSH)(GetStockObject(LTGRAY_BRUSH));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY20230821GAMEP);
	//wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	int xResolution = GetSystemMetrics(SM_CXSCREEN);
	int yResolution = GetSystemMetrics(SM_CYSCREEN);

	int winPosX = xResolution / 2 - 1280 / 2;
	int winPosY = yResolution / 2 - 720 / 2;

	RECT rect = { winPosX,winPosY,winPosX + 1280,winPosY + 720 };

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_HSCROLL, true);


	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_HSCROLL,
		winPosX, winPosY, 1280, 720, nullptr, nullptr, hInstance, nullptr);

	MoveWindow(hWnd, winPosX, winPosY, rect.right - rect.left, rect.bottom - rect.top, true);
	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static UINT iCount = 0;
	static char arr[100];
	//static wchar_t wstr[100];
	static wchar_t wstr[10][11];
	static int  count, yPos, xPos, line;
	static SIZE size;

	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		count = line = 0;
		yPos = 0;
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	//무효화 영역 발생 함수
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);

		HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
		SelectObject(hdc, hFont);

		GetTextExtentPoint(hdc, wstr[line], wcslen(wstr[line]), &size);

		for (int i = 0; i < +line; i++) {
			TextOut(hdc, 0, i * 20, wstr[i], wcslen(wstr[i]));
		}
		SetCaretPos(size.cx, line * 20);
		//AddFontResource(TEXT("IsiniScript.ttf"));


		HPEN hPen = CreatePen(PS_DASHDOT, 3, RGB(0, 0, 255));
		HBRUSH hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
		HPEN hDefaultPen = (HPEN)SelectObject(hdc, hPen);
		RECT rect = { 0,0,165,720 };
		//DrawText(hdc, wstr, wcslen(wstr), &rect, DT_TOP | DT_WORDBREAK |DT_EDITCONTROL);

		SelectObject(hdc, hBrush);
		DeleteObject(hPen);

		//for (int i = 0; i < 1000; i++) {
		//    int x = rand() % 100;
		//    int y = rand() % 100;
		//    SetPixel(hdc, x,y,RGB(255,0,0));
		//}
		//for (int i = 0; i < 16; i++) {
		//    MoveToEx(hdc, i * 1280 / 16, 0, nullptr); //시작 지점
		//    LineTo(hdc, i* 1280 /16, 720);
		//}                           
		//for (int i = 0; i < 9; i++) {
		//    MoveToEx(hdc, i, i * 720 /9, nullptr); //시작 지점
		//    LineTo(hdc, 1280, i * 720 /9);
		//}

		int targetCnt = 25;

		for (int i = 0; i < targetCnt; ++i) {
			int left = 100 + (i % 5 * 70);
			int top = 100 + (i / 5 * 70);

			if (i / 5 % 2 == 0) {
				Rectangle(hdc, left, top, left + 50, top + 50);
			}
			else {
				Ellipse(hdc, left, top, left + 50, top + 50);
			}
		}

		//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		//wstring str = L"겜프 2학기 시작";

		//TextOut(hdc,10,10,str.c_str(), str.length());

		//RECT rect = { 50,50,80,80};
		//Rectangle(hdc, rect.left,rect.top,rect.right,rect.bottom);
		//DrawText(hdc,str.c_str(),str.length(),&rect,DT_RIGHT | DT_CENTER);

		//

		////사각형 그리기

		////Rectangle(hdc,10,10,110,110);
		////Ellipse(hdc, 50, 50, 150, 150);
		//EndPaint(hWnd, &ps);

		Rectangle(hdc,
			 ptObjPos.x - ptObjScale.x / 2
			, ptObjPos.y - ptObjScale.y / 2
			, ptObjPos.x + ptObjScale.x / 2
			, ptObjPos.y + ptObjScale.y / 2
			);
		EndPaint(hWnd,&ps);
	}
	break;
	case WM_KEYDOWN:
		switch (wParam)
		{

		case VK_LEFT:
				ptObjPos.x -= 10;
				break;
		case VK_RIGHT:
			ptObjPos.x += 10;
			break;
		}
		InvalidateRect(hWnd, nullptr, true);

	case WM_CHAR:
	{
		hdc = GetDC(hWnd);
		//if (wParam == VK_BACK && count > 0) {
		//	count--;
		//}
		//else if (wParam == VK_SPACE)
		//{
		//	count = 0;
		//}
		//else {
		//	wstr[count++] = wParam;
		//}
		//wstr[count] = NULL;
		if (wParam == VK_RETURN || line >= 10) {
			if (line < 9) {
				line++;
				count = 0;
			}
		}
		else if (count < 10) {
			wstr[line][count++] = wParam;
		}
		wstr[line][count] = NULL;
		InvalidateRect(hWnd, nullptr, false);
		ReleaseDC(hWnd, hdc);																	

	}
	break;
	case WM_DESTROY:
		//MessageBox(hWnd, L"X버튼이 눌렸습니다.", L"WM_DESTROY", MB_OK);
		_itoa_s(iCount, arr, 10);
		//MessageBoxA(hWnd,arr,"WM_DESTROY",MB_OK);
		HideCaret(hWnd);
		DestroyCaret();
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDBLCLK:
		//SetDoubleClickTime();

		MessageBox(hWnd, L"왼쪽 마우스 더블클릭", L"WM_DESTROY", MB_OKCANCEL | MB_ICONSTOP);
		break;
	default:
		break;
	}

	iCount++;
	return DefWindowProc(hWnd, message, wParam, lParam);
	//return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
