#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "GameLogic.h"
#include "Console.h"
using namespace std;

void Render(char maze[VERTICAL][HORIZON], PPLAYER player){
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZON; j++) {
            bool drawed = false;
            if (player->pos.x == j && player->pos.y == i) {
                //SetColor(COLOR::LIGHT_BLUE, COLOR::BLACK);
                drawed = true;
                cout << "☎";
            }

            if (drawed) continue;

            if (maze[i][j] == '0') {
                cout << '0';
            }
            else if (maze[i][j] == '1') {
                cout << '1';
            }
            SetColor(COLOR::WHITE, COLOR::BLACK);
        }
        cout << endl;
    }
}
void Fire(char maze[VERTICAL][HORIZON], POS startPos, GUN gun,KEY_CODE prevKeyCode){
    switch (prevKeyCode)
    {
    case KEY_CODE::NONE: {
        startPos.y--;
        maze[startPos.y][startPos.x] = '1';
        break;
    }
    case KEY_CODE::UP: {
        startPos.y--;
        maze[startPos.y + 1][startPos.x] = '1';
        break;
    }
    case KEY_CODE::DOWN: {
        startPos.y++;
        maze[startPos.y][startPos.x] = '1';
        break;
    }
    case KEY_CODE::LEFT: {
        startPos.x--;
        maze[startPos.y][startPos.x] = '1';
        break;
    }
    case KEY_CODE::RIGHT: {
        startPos.x++;
        maze[startPos.y][startPos.x] = '1';
        break;
    }
    case KEY_CODE::SPACE: {
        break;
    }
    default: {
        break;
    }
    }
}

void Update(char maze[VERTICAL][HORIZON], PPLAYER player,KEY_CODE &keyCode){
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        --player->pos.y;
        keyCode = KEY_CODE::UP;
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        ++player->pos.y;
        keyCode = KEY_CODE::DOWN;
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        --player->pos.x;
        keyCode = KEY_CODE::LEFT;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        ++player->pos.x;
        keyCode = KEY_CODE::RIGHT;
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        Fire(maze,player->pos, player->gun,keyCode);
    } //발사 로직
    
    Sleep(100);
}


void Init(char maze[VERTICAL][HORIZON],PPLAYER player,PPOS startPos) {
    ConsoleCursor(false, 1);
    startPos->x = 0;
    startPos->y = 0;
    
    BULLET bullet = {*startPos,3,false};
    GUN gun = {bullet};

    PLAYER setPlayer = { *startPos, gun};

    *player = setPlayer;
    strcpy_s(maze[0], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[1], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[2], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[3], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[4], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[5], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[6], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[7], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[8], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[9], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[10], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[11], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[12], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[13], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[14], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[15], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[16], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[17], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[18], "00000000000000000000000000000000000000000000000000");
    strcpy_s(maze[19], "00000000000000000000000000000000000000000000000000");
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
