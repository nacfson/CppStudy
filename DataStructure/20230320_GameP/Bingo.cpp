#include <iostream>
#include <Windows.h>
using namespace std;
//���� ���� enum vs ���� �ִ� enum class
enum class AI_MODE
{
	NULLMODE = 0,
	AI_EASY = 1,
	AI_NORMAL
};
enum class LINE_NUMBER
{
	LN_H1,LN_H2,LN_H3,LN_H4,LN_H5,
	LN_V1,LN_V2,LN_V3,LN_V4,LN_V5,
	LN_LT,LN_RT
};
class Agent
{
public:
	Agent(string name, AI_MODE mode = AI_MODE::NULLMODE) : name{ name }, ai { mode }{}; //����� ����ȯ
	void Init();
	int CountBingo();
	void AISystem(Agent &player,AI_MODE mode,int input);
	void EasyAI(Agent &player, int input);
	void NormalAI(Agent& player, int input);
	void RenderNumber();
	void Update(int& input);
	int SetRandomNum();
	bool Bingo();
	AI_MODE ai{AI_MODE::NULLMODE};
	string name{"AI"};
private:
	int GetMaxArrayValue();
	int _iBingo{ 0 };
	int _iNumber[25] = {};
	int _intMaxArray[25] = {};
};
bool GameCheck(Agent& player, Agent& ai);
bool RenderGame(Agent& player, Agent& ai);
int main(void)
{
	srand((unsigned int)time(NULL));
	int aiMode;
	cout << "AI�� ���̵��� �����ϼ��� (1: Easy, 2: NORMAL, 3: HARD)" << endl;
	cin >> aiMode;

	Agent player{ "Player" };
	Agent ai{ "AI", static_cast<AI_MODE>(aiMode) }; 

	player.Init();
	ai.Init();

	while (1)
	{
		if (RenderGame(player, ai))
		{
			//0 �Է½� ���� ����
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
			if (_iNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else
				cout << _iNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
	_iBingo = CountBingo();
	cout << "BingoLine: " << _iBingo << endl;
}

void Agent :: Init()
{
	for (int i = 0; i < 25 ; i++)
	{
		_iNumber[i] = i + 1;
	}
	for (int i = 0; i < 25; i++)
	{
		_intMaxArray[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100 + (int)ai * 100; i++)
	{
		idx1 = rand() % 24 + 1;
		idx2 = rand() % 24 + 1;
		iTemp = _iNumber[idx1];
		_iNumber[idx1] = _iNumber[idx2];
		_iNumber[idx2] = iTemp;
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
			if (_iNumber[i*5+j] == INT_MAX)
			{
				iHorStar++;
			}
			if (_iNumber[j * 5 + i] == INT_MAX)
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
		if (_iNumber[i] == INT_MAX)
		{
			iLTStar++;
		}
	}
	for (int i = 0; i < 21; i += 4)
	{
		if (_iNumber[i] == INT_MAX)
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
		if (input == _iNumber[i])
		{
			_intMaxArray[_iNumber[i]] = INT_MAX;
			_iNumber[i] = INT_MAX;
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
	case AI_MODE::AI_NORMAL:
	{
		NormalAI(player, input);
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

void Agent::NormalAI(Agent& player, int input)
{
	Update(input);
	int value = GetMaxArrayValue();
	Update(value);
	player.Update(value);
}

int Agent::GetMaxArrayValue()
{
	int iLine = 0;
	int iStartCnt = 0;
	int iSaveCnt = 0;
	// BingoCount ����
	for (int i = 0; i < 5; i++)
	{
		iStartCnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (_iNumber[i * 5 + j] == INT_MAX)
			{
				iStartCnt++;
			}
		}
		if (iStartCnt < 5 && iSaveCnt < iStartCnt) // ���� Ȯ���� ���� ���� �̰ž�
		{
			iLine = i; // 0���� 4           
			iSaveCnt = iStartCnt;
		}
	}
	//������ üũ
	for (int i = 0; i < 5; i++)
	{
		iStartCnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (_iNumber[j* 5 + i] == INT_MAX)
			{
				iStartCnt++;
			}
		}
		if (iStartCnt < 5 && iSaveCnt < iStartCnt) // ���� Ȯ���� ���� ���� �̰ž�
		{
			iLine = i + 5; // 0���� 4           
			iSaveCnt = iStartCnt;
		}
	}

	iStartCnt = 0;
	for (int i = 0; i < 25; i+=6)
	{
		if (_iNumber[i] == INT_MAX)
		{
			iStartCnt++;
		}
	}
	if (iStartCnt < 5 && iSaveCnt < iStartCnt) // ���� Ȯ���� ���� ���� �̰ž�
	{
		iLine = (int)LINE_NUMBER::LN_LT;
		iSaveCnt = iStartCnt;
	}

	iStartCnt = 0;
	for (int i = 0; i <= 20; i+=4)
	{
		if (_iNumber[i] == INT_MAX)
		{
			iStartCnt++;
		}
	}
	if (iStartCnt < 5 && iSaveCnt < iStartCnt) // ���� Ȯ���� ���� ���� �̰ž�
	{
		iLine = (int)LINE_NUMBER::LN_RT;
		iSaveCnt = iStartCnt;
	}
	//����
	if (iLine <= (int)LINE_NUMBER::LN_H5)
	{
		for (int i = 0; i < 5; i++)
		{
			if (_iNumber[iLine * 5 + i] != INT_MAX)
			{
				return _iNumber[iLine * 5 + i];
			}
		}
	}
	else if (iLine <= (int)LINE_NUMBER::LN_H5)
	{
		for (int i = 0; i < 5; i++)
		{
			if (_iNumber[i] != INT_MAX)
			{
				return _iNumber[i * 5 + (iLine - 5)];
			}
		}
	}
	else if (iLine == (int)LINE_NUMBER::LN_LT)
	{
		for (int i = 0; i < 5; i+=6)
		{
			if (_iNumber[i] != INT_MAX)
			{
				return _iNumber[i];
			}
		}
	}
	else if (iLine == (int)LINE_NUMBER::LN_RT)
	{
		for (int i = 0; i < 5; i += 4)
		{
			if (_iNumber[i] != INT_MAX)
			{
				return _iNumber[i];
			}
		}
	}
	else
	{
		return SetRandomNum();
	}

	return -1;
}

int Agent ::SetRandomNum()
{
	int ran = rand() % 24 + 1;
	int arrayValue = _intMaxArray[ran];
	while (arrayValue == INT_MAX)
	{
		ran = rand() % 24 + 1;
		arrayValue = _intMaxArray[ran];
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
			cout << endl << endl << "�����ϴ�";
			return true;
		}
		system("cls");
		player.RenderNumber();
		ai.RenderNumber();
		cout << endl << endl << "�̰���ϴ�";
		return true;
	}
	if (ai.Bingo())
	{
		system("cls");
		player.RenderNumber();
		ai.RenderNumber();
		cout << endl << endl <<"�����ϴ�";
		return true;
	}
	return false;
}
bool RenderGame(Agent &player, Agent &ai)
{
	int input;

	cout << "===========================================" << endl;
	cout << "|\t ���� ���� \t" << endl;
	cout << "===========================================" << endl;
	cout << "�������� 5�� �̻��� �Ǹ� ���ӿ��� �¸��մϴ�." << endl;
	cout << "===========================================" << endl;
	system("cls");
	player.RenderNumber();
	ai.RenderNumber();
	cin >> input;
	if (input == 0)
	{
		cout << "������ �����մϴ�." << endl;
		return true;
	}

	else if (input < 1 || input > 25)
	{
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
		return false;
	}
	player.Update(input);
	ai.AISystem(player,ai.ai,input);

	return false;
}

