#include <iostream>
#include <Windows.h>
#include <vector>
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
	void RenderNumber();
	void Update(int& input);
	int SetRandomNum();
	AI_MODE ai{AI_MODE::NULLMODE};
	string name{"AI"};
	int iBingo{ 0 };
	int iNumber[25] = {};
	int intMaxArray[25] = {};
};


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
int Agent::SetRandomNum()
{
	srand((unsigned int)time(NULL));
	int ran = rand() % 24 + 1;
	int arrayValue = intMaxArray[ran];
	while (arrayValue == INT_MAX)
	{
		ran = rand();
		arrayValue = intMaxArray[ran];
	}
	return arrayValue;
}
int main(void)
{
	int aiMode;
	int input;
	cin >> aiMode;
	vector<Agent> players;

	Agent player("Player");
	Agent ai("AI", (AI_MODE)aiMode);

	players.push_back(player);
	players.push_back(ai);

	players[0].Init();
	players[1].Init();

	while (1)
	{
		cout << "===========================================" << endl;
		cout << "|\t 빙고 게임 \t" << endl;
		cout << "===========================================" << endl;
		cout << "빙고줄이 5줄 이상이 되면 게임에서 승리합니다." << endl;
		cout << "===========================================" << endl;
		///system("cls");
		for (int i = 0; i < players.size(); i++)
		{
			players[i].RenderNumber();
		}
		cin >> input;
		if (input == 0)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else if (input < 1 || input > 25)
		{
			cout << "잘못입력하였습니다." << endl;
			continue;
		}
		player.Update(input);
		int aiRandValue = ai.SetRandomNum();
		ai.Update(aiRandValue);

		//if (iBingo > 4)
		//{
		//	cout << "게임에서 승리하였습니다.";
		//	break;
		//}
		//cout << "숫자를 입력하세요.(0: 종료)" << endl;
		//cin >> input;
		//if (input == 0)
		//{
		//	cout << "게임을 종료합니다." << endl;
		//	break;
		//}
		//else if (input < 1 || input > 25)
		//{
		//	cout << "잘못입력하였습니다." << endl;
		//	continue;
		//}	
	}

	return 0;
}