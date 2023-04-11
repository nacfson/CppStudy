#include "bombman.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "console.h"
using namespace std;


void AsciiArt() {

    int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"██████   ██████  ███    ███ ██████  ███    ███  █████  ███    ██" << endl;
    wcout << L"██   ██ ██    ██ ████  ████ ██   ██ ████  ████ ██   ██ ████   ██" << endl;
    wcout << L"██████  ██    ██ ██ ████ ██ ██████  ██ ████ ██ ███████ ██ ██  ██" << endl;
    wcout << L"██   ██ ██    ██ ██  ██  ██ ██   ██ ██  ██  ██ ██   ██ ██  ██ ██" << endl;
    wcout << L"██████   ██████  ██      ██ ██████  ██      ██ ██   ██ ██   ████" << endl;
    int curMode = _setmode(_fileno(stdout), prevMode);

    Gotoxy(40,10);
    cout << "게임시작";
    Gotoxy(40, 11);
    cout << "게임 메뉴";
    Gotoxy(40, 12);
    cout << "게임 종료";






}