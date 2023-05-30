#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "GameLogic.h"
#include "Console.h"
using namespace std;

void Render(char maze[VERTICAL][HORIZON], PPLAYER player){

}

void Init(char maze[VERTICAL][HORIZON], PPOS startPos){

}

void Fire(PPOS startPos, PGUN gun)
{
}

void Update(char maze[VERTICAL][HORIZON], PPLAYER player){

}

void AsciiArt(){
    int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"   ____  _                 _     _____ _            _____                            " << endl;
    wcout << L"  / ___|| |__   ___   ___ | |_  |_   _| |__   ___  | ____|_ __   ___ _ __ ___  _   _ " << endl;
    wcout << L"  \\___ \\| '_ \\ / _ \\ / _ \\| __|   | | | '_ \\ / _ \\ |  _| | '_ \\ / _ \\ '_ ` _ \\| | | |" << endl;
    wcout << L"   ___) | | | | (_) | (_) | |_    | | | | | |  __/ | |___| | | |  __/ | | | | | |_| |" << endl;
    wcout << L"  |____/|_| |_|\\___/ \\___/ \\__|   |_| |_| |_|\\___| |_____|_| |_|\\___|_| |_| |_|\\__, |" << endl;
    wcout << L"                                                                               |___/ " << endl;
    int curMode = _setmode(_fileno(stdout), prevMode);
}
