#include "pch.h"
#include "BaseWindow.h"
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
//  BaseWindow* game = new BaseWindow();
    BaseWindow game({ WINDOW_WIDTH, WINDOW_HEIGHT }); // 괄호에다가 내 게임의 해상도를 넣어서 바로 만들고싶은거야.
    game.Run(hInstance, nCmdShow);

}