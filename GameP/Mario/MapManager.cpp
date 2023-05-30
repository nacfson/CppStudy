#include "MapManager.h"
#include "Stage.h"
MapManager* MapManager::m_pInst = nullptr;
MapManager::MapManager() {
    for (int i = 0; i < 3; i++) {
        map[i] = nullptr;
    }
}
MapManager::~MapManager(){
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(map[i]);
    }
}

bool MapManager::Init(){
    char* stageName[3] = {(char*)"Stage1.txt",(char*)"Stage2.txt",(char*)"Stage3.txt"};
    for (int i = 0; i < 3; i++) {
        map[i] = new Stage;
        if (!map[i]->Init(stageName[i])) {
            return false;
        }
    }
    return true;
}

void MapManager::Run(int currentStage){
    this->currentStage = currentStage;
    map[this->currentStage]->Render();




}
