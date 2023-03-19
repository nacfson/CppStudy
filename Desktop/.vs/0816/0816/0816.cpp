//
//
//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;
////class CPerson
////{
////public:
////	void Set(string name, int age, int gender)
////	{
////		m_Name = name;
////		m_Age = age;
////		m_Gender = gender;
////	}
////public:
////
////	string GetName()
////	{
////		return m_Name;
////	}
////	int GetAge()
////	{
////		return m_Age;
////	}
////	int GetGender()
////	{
////		return m_Gender;
////	}
////private:
////	string m_Name = { 0 };
////	int m_Age = 0;
////	int m_Gender = 0;
////
////};
////class CStudent : public CPerson
////{
////
////};
//
//int main()
//{
//	//vector<string> vt;
//	//vt = { "문소리","라미란","조여정","한지민","나문희","김민희" };
//	//vector<string>::iterator it = vt.begin();
//	//for (int i= 0; i<6; i++)
//	//{
//	//	switch (i)
//	//	{
//	//	case 0:
//	//		cout << it[i];
//	//		break;
//	//	case 2:
//	//		cout << it[i];
//	//		break;
//	//	case 4:
//	//		cout << it[i];
//	//		break;
//
//	//	}
//	//}
//
//	//enum feeling { happy = 1,good,sad,bad,mad,terrible };
//	//
//	//int arrayCount;
//	//cout << "how are you today?"<<endl<<"1.happy/ 2. good/ 3. sad / 4. bad / 5.mad / 6. terrible";
//	//cin >> arrayCount;
//
//	//switch (arrayCount)
//	//{
//	//	case happy:
//	//		cout << "tteokbokki";
//	//		break;
//	//	case good:
//	//		cout << "chicken";
//	//		break;
//	//	case sad:
//	//		cout << "pizza";
//	//		break;
//	//	case bad:
//	//		cout << "rice";
//	//		break;
//	//	case mad:
//	//		cout << "hamburger";
//	//		break;
//	//	case terrible:
//	//		cout << "JJajang";
//	//		break;
//	//}
//	//CStudent s2:
//	//s1.Set("rlaalstn",17)
//
//}
#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string new_id) {

    string answer;
    if (new_id.length() <= 2)
    {
        while (new_id.length() < 3)
        {
            new_id.push_back(new_id[new_id.length() - 1]);
        }
    }
    answer = new_id;
    cout << answer;
    return answer;
    //if (new_id.length() >= 3 || new_id.length() <= 15)
    //{
    //    for (int i = 0; i < new_id.length())
    //    {

    //    }

    //}
}
int main()
{
    string key = "ke";
    solution(key);
    return 0;
}


