#include <iostream>
#include <Windows.h>
using namespace std;
enum class AI_MODE
{
	NULLMODE = 0,
	AI_EASY =1,
	AI_NORMAL
};
class Agent
{
public:
	Agent(string name, AI_MODE mode = AI_MODE::NULLMODE) : name{ name }, ai { mode }{};
	void Init();
	int CountBingo();
	void AISystem(Agent &player,AI_MODE mode,int input);
	void EasyAI(Agent &player, int input);
	void RenderNumber();
	void Update(int& input);
	int SetRandomNum();
	bool Bingo();
	AI_MODE ai{AI_MODE::NULLMODE};
	string name{"AI"};
	int iBingo{ 0 };
	int iNumber[25] = {};
	int intMaxArray[25] = {};
};
bool GameCheck(Agent& player, Agent& ai);
bool RenderGame(Agent& player, Agent& ai);
int main(void)
{
	int aiMode;
	cout << "AI의 난이도를 설정하세요 (1: Easy, 2: NORMAL, 3: HARD)" << endl;
	cin >> aiMode;

	Agent player{ "Player" };
	Agent ai{ "AI",(AI_MODE)aiMode };

	player.Init();
	ai.Init();

	while (1)
	{
		if (RenderGame(player, ai))
		{
			//0 입력시 게임 종료
			break;
		}
		if (GameCheck(player, ai))
		{
			break;
		}
	}
	return 0;
}

void Agent::RenderNumber()
{
	cout << "=======================" << name <<"====================" << endl;
	if (ai != AI_MODE::NULLMODE)
	{
		cout << "LEVEL: " << (int)ai << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (iNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else
				cout << iNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
	iBingo = CountBingo();
	cout << "BingoLine: " << iBingo << endl;
}

void Agent :: Init()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25 ; i++)
	{
		iNumber[i] = i + 1;
	}
	for (int i = 0; i < 25; i++)
	{
		intMaxArray[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100 + (int)ai * 100; i++)
	{
		idx1 = rand() % 24 + 1;
		idx2 = rand() % 24 + 1;
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
}

int Agent::CountBingo()
{
	int iCheckBingo = 0;
	int iHorStar = 0, iVerStar = 0,
		iLTStar = 0,
		iRTStar = 0;
	for (int i = 0; i < 5; i++)
	{
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++)
		{
			if (iNumber[i*5+j] == INT_MAX)
			{
				iHorStar++;
			}
			if (iNumber[j * 5 + i] == INT_MAX)
			{
				iVerStar++;
			}
		}
		if (iHorStar == 5)
			iCheckBingo++;
		if (iVerStar == 5)
			iCheckBingo++;
	}
	for (int i = 0; i < 25; i += 6)
	{
		if (iNumber[i] == INT_MAX)
		{
			iLTStar++;
		}
	}
	for (int i = 0; i < 21; i += 4)
	{
		if (iNumber[i] == INT_MAX)
		{
			iRTStar++;
		}
	}
	if (iLTStar == 5)
		iCheckBingo++;
	if (iRTStar == 5)
		iCheckBingo++;
	
	return iCheckBingo;
}
void Agent::Update(int& input)
{
	for (int i = 0; i < 25; i++)
	{
		if (input == iNumber[i])
		{
			intMaxArray[iNumber[i]] = INT_MAX;
			iNumber[i] = INT_MAX;
		}
	}
}
void Agent::AISystem(Agent &player,AI_MODE mode,int input)
{
	switch (mode)
	{
	case AI_MODE::AI_EASY:
		{
			EasyAI(player,input);
			break;
		}
	}

}
void Agent::EasyAI(Agent &player,int input)
{
	Update(input);
	int randValue = SetRandomNum();
	Update(randValue);
	player.Update(randValue);
}

int Agent ::SetRandomNum()
{
	srand((unsigned int)time(NULL));
	int ran = rand() % 24 + 1;
	int arrayValue = intMaxArray[ran];
	while (arrayValue == INT_MAX)
	{
		ran = rand() % 24 + 1;
		arrayValue = intMaxArray[ran];
	}
	return arrayValue;
}

bool Agent::Bingo()
{
	if (CountBingo() > 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GameCheck(Agent &player, Agent &ai)
{
	if (player.Bingo())
	{
		if (ai.Bingo())
		{
			system("cls");
			player.RenderNumber();
			ai.RenderNumber();
			cout << endl << endl << "비겼습니다";
			return true;
		}
		system("cls");
		player.RenderNumber();
		ai.RenderNumber();
		cout << endl << endl << "이겼습니다";
		return true;
	}
	if (ai.Bingo())
	{
		system("cls");
		player.RenderNumber();
		ai.RenderNumber();
		cout << endl << endl <<"졌습니다";
		return true;
	}
	return false;
}
bool RenderGame(Agent &player, Agent &ai)
{
	int input;

	cout << "===========================================" << endl;
	cout << "|\t 빙고 게임 \t" << endl;
	cout << "===========================================" << endl;
	cout << "빙고줄이 5줄 이상이 되면 게임에서 승리합니다." << endl;
	cout << "===========================================" << endl;
	system("cls");
	player.RenderNumber();
	ai.RenderNumber();
	cin >> input;
	if (input == 0)
	{
		cout << "게임을 종료합니다." << endl;
		return true;
	}

	else if (input < 1 || input > 25)
	{
		cout << "잘못입력하였습니다." << endl;
		return false;
	}
	player.Update(input);
	ai.AISystem(player,ai.ai,input);

	return false;
}

