
#include <iostream>
using namespace std;
void Upgrade(float percent,float fPercent)
{
    if (fPercent < percent)
    {
        cout << "강화성공" << endl;
    }
    else
    {
        cout << "강화 실패" << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    cout << "==================" << endl;
    cout << "스타포스 강화 게임" << endl;
    cout << "==================" << endl;

    int iUpgrade = 0;
    float fPercent;
    //0~2성 : 90% 확률, 3~5성: 50%, 6~9성: 10%, 10성<: 1% 확률로 성공
    cout << "현재 무기는 몇성인가요?:" << endl;
    cin >> iUpgrade;
    fPercent = (rand() % 10001) * 0.01f;
    cout << "현재 무기 Upgrade: " << iUpgrade << "성" << endl;
    cout << "강화확률 Percent: " << fPercent << "%" << endl;





    cout << "강화하시겠습니까? 예: 1, 아니오 : 0" << endl;

    int iInput;
    cin >> iInput;


    if (iInput == 0)
    {
        return 0;
    }
    if (iUpgrade <= 2)
    {
        Upgrade(90.f,fPercent);
    }
    else if (iUpgrade <= 5)
    {
        Upgrade(50.f,fPercent);
    }
    else if (iUpgrade <= 9)
    {
        Upgrade(10.f, fPercent);
    }
    else
    {
        Upgrade(1.f, fPercent);
    }


    cin >> iUpgrade;
    srand((unsigned int)time(NULL));
    int ran = rand();






    return 0;
}

