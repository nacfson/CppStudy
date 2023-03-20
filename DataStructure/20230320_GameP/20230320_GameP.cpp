#include <iostream>
#include <conio.h>
using namespace std;
//getch(),kbhit();

int main(void)
{
    long long curtTime = time(NULL);
    while (1)
    {
        if (_kbhit)
        {
            cout << "끝!" << endl;
            break;
        }

    }
    if (time(NULL) - curtTime == 10)
    {
        cout << "정답";
    }
    else if (time(NULL) - curtTime < 10)
    {
        cout << " 빠름";
    }
    else
    {
        cout << "느림";
    }
    return 0;
}

