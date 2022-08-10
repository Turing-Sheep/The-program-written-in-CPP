#include<iostream>
using namespace std;
#include"SpeechManager.h"
int main()
{

	Speech_Manager sm;
	while (true)
	{
		sm.Show_Menu();
		int choice;
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.StartSpeech();
			system("pause");
			system("cls");
			break;
		case 2:
			sm.show_Record();
			system("pause");
			system("cls");
			break;
		case 3:
			sm.Clear_Record();
			break;
		case 4:
			sm.Exit_System();
			break;
		default:
			system("cls");
			break;
		}


	}
	system("pause");
	return 0;
}