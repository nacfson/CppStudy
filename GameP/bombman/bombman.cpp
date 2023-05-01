﻿#include "bombman.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
#include "console.h"
#include "StartScene.h"
using namespace std;


void AsciiArt() {

    int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"██████   ██████  ███    ███ ██████  ███    ███  █████  ███    ██" << endl;
    wcout << L"██   ██ ██    ██ ████  ████ ██   ██ ████  ████ ██   ██ ████   ██" << endl;
    wcout << L"██████  ██    ██ ██ ████ ██ ██████  ██ ████ ██ ███████ ██ ██  ██" << endl;
    wcout << L"██   ██ ██    ██ ██  ██  ██ ██   ██ ██  ██  ██ ██   ██ ██  ██ ██" << endl;
    wcout << L"██████   ██████  ██      ██ ██████  ██      ██ ██   ██ ██   ████" << endl;
    int curMode = _setmode(_fileno(stdout), prevMode);

    //Gotoxy(40,10);
    //cout << "게임시작";
    //Gotoxy(40, 11);
    //cout << "게임 메뉴";
    //Gotoxy(40, 12);
    //cout << "게임 종료";


}

void Init(char maze[VERTICAL][HORIZON], PPLAYER player, PPOS startPos, PPOS endPos){
    system("mode con cols=80 lines=30 | title bombman");
    SetConsoleTitle(TEXT("Bombman"));
    ConsoleCursor(false, 1);

    //(*startpos).x = 0;
    startPos->x = 0;
    startPos->y = 0; //19,13

    endPos->x = 19;
    endPos->y = 13;

    PLAYER setPlayer = {*startPos,1,0,false,false,false};


    *player = setPlayer;

    strcpy_s(maze[1], "21100000000000000000"      );
    strcpy_s(maze[2], "10111111111000000000"      );
    strcpy_s(maze[3], "00100000001111000000"      );
    strcpy_s(maze[4], "00100000000001000000"      );
    strcpy_s(maze[5], "00000000000001000000"      );
    strcpy_s(maze[6], "00000000000001000000"      );
    strcpy_s(maze[7], "00000000000001000000"      );
    strcpy_s(maze[8], "00000000000001000000"      );
    strcpy_s(maze[9], "00111111100001000000"      );
    strcpy_s(maze[10],"00000000000001000000"      );
    strcpy_s(maze[11],"00000000000001000000"      );
    strcpy_s(maze[12],"00000000000001000000"      );
    strcpy_s(maze[13],"00111111111111111113"      );
    strcpy_s(maze[14],"00000100000000000000"      );
    strcpy_s(maze[15],"00000100000000000000"      );
    strcpy_s(maze[16],"00000100000000000000"      );
    strcpy_s(maze[17],"00000100000000000000"      );
    strcpy_s(maze[18],"00000100000000000000"      );
    strcpy_s(maze[19],"00000111111111100000"      );

}

void Update(char maze[VERTICAL][HORIZON], PPLAYER player, vector<BOOM>& vecBoom, vector<POS>& boomEffect){
    player->newPos = player->pos;
    if (GetAsyncKeyState(VK_UP) & 0x8000)
        --player->newPos.y;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        ++player->newPos.y;
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        --player->newPos.x;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        ++player->newPos.x;

    //벽 밖인지 Clamp
    player->newPos.x = std::clamp(player->newPos.x, 0, HORIZON-2);
    player->newPos.y = std::clamp(player->newPos.y, 0, VERTICAL-1);
    if (maze[player->newPos.y][player->newPos.x] != '0') {
        player->pos = player->newPos;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        BombCreate(player, maze);
    }
    if (GetAsyncKeyState('E') & 0x8000) {
        if (player->isPush) {
            player->isPushOnOff = !player->isPushOnOff;
        }
    }
    Sleep(100);
}

void Render(char maze[VERTICAL][HORIZON], PPLAYER player, std::vector<POS>& boomEffect){
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZON; j++) {
            if (player-> pos.x == j && player->pos.y == i) {
                cout << "?";
            }
            else if (maze[i][j] == (char)MAPTYPE::WALL) {
                cout << "■";
            }
            else if (maze[i][j] == (char)MAPTYPE::ROAD) {
                cout << " ";
            }
            else if (maze[i][j] == (char)MAPTYPE::START) {
                cout << "®";
            }
            else if (maze[i][j] == (char)MAPTYPE::END) {
                cout << "♨";
            }
            else if (maze[i][j] == (char)MAPTYPE::WATERBOMB) {
                SetColor(COLOR::MINT, COLOR::BLACK);
                cout << "※";
            }
            else if (maze[i][j] == (char)MAPTYPE::TWINKLE) {
                SetColor(COLOR::SKYBLUE, COLOR::BLACK);
                cout << "◆";
            }
            else if (maze[i][j] == (char)MAPTYPE::POWER) {
                cout << "↔";
            }
            else if (maze[i][j] == (char)MAPTYPE::SLIME) {
                cout << "♣";
            }
            else if (maze[i][j] == (char)MAPTYPE::PUSH) {
                cout << "▒";
            }
            SetColor(COLOR::WHITE, COLOR::BLACK);
            
        }
        cout << endl;
    }

    cout << "SPACEBAR: 폭탄설치, E: 푸시능력 ON/OFF" << endl;
    cout << "폭탄 파워: " << player->bombPower << endl;
    if (player->isPushOnOff) {
        cout << "푸시 능력: ON " << endl;
    }
    else {
        cout << "푸시 능력: OFF" << endl;
    }
    if (player->isGhost) {
        cout << "슬라임 능력: ON " << endl;
    }
    else {
        cout << "슬라임 능력: OFF" << endl;
    }


}

void BombCreate(PPLAYER player, char maze[VERTICAL][HORIZON], std::vector<BOOM>& vecBomb){
    
    //폭탄 개수 5개
    if (player->bombCount == 5) return;

    //폭탄 설치 기능
    if (maze[player->pos.y][player->pos.x] = (char)MAPTYPE::ROAD) {
        maze[player->pos.y][player->pos.x] = 'b';
        player->bombCount += 1;

        vecBomb.push_back({ player->pos.x, player->pos.y, 50, false
            });

    }


}