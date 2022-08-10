#include"SpeechManager.h"

Speech_Manager::Speech_Manager()
{
	this->initSpeaker();
	this->createSpeaker();
	this->load_Record();
}

Speech_Manager::~Speech_Manager()
{

}

void Speech_Manager::Show_Menu()
{
	cout << "��ӭʹ���ݽ���������ϵͳ��" << endl;
	cout << "1����ʼ�ݽ�����" << endl;
	cout << "2���鿴�����¼" << endl;
	cout << "3����ձ�����¼" << endl;
	cout << "4���˳���������" << endl;

}

void Speech_Manager::Exit_System()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);

};

void Speech_Manager::initSpeaker()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
};

void Speech_Manager::createSpeaker()
{
	
	for (int i = 0;i <12;i++)
	{
		string nameSeed = "ABCDEFJHIJKL";
		string name = "ѡ��";
		name += nameSeed[i];

		speaker sp;
		sp.name = name;

		for (int j = 0;j < 2;j++)
		{
			sp.score[j] = 0;
		}

		//����ѡ�ֵı�ţ����ҷ��뵽V1������
		this->v1.push_back(i + 10001);

		//ѡ�ֵı�ź�ѡ�ַ��뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void Speech_Manager::StartSpeech()
{
	//��һ�ֿ�ʼ����

	//1����ǩ
	this->SpeechDraw();
	system("pause");
	//2������
	this->StartCompetition();
	system("pause");
	//3����ʾ�����Ľ��
	this->show_result();

	//�ڶ��ֱ�����ʼ
	this->m_Index++;
	//1����ǩ
	this->SpeechDraw();
	system("pause");
	//2������
	this->StartCompetition();
	system("pause");
	//3����ʾ���յĽ��
	this->show_result();
	Save_Record();
	cout << "���α�����ϣ�" << endl;
	this->initSpeaker();
	this->createSpeaker();
	this->load_Record();
}

void Speech_Manager::SpeechDraw()
{
	srand((unsigned int)time(NULL));
	cout << "          ��" << this->m_Index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "_______________________________________________________________" << endl;
	cout << endl;
	cout << "��ǩ���˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
	    }
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "_______________________________________________________________" << endl;
}

void Speech_Manager::StartCompetition()
{
	cout << "           ��������������" << this->m_Index << "�ֱ�����ʼ������������" << endl;
	
	//����һ��������¼ѡ�ֵķ����ͱ�ţ������ɼ�
	multimap<double, int, greater<double>>Final_List;
	//��¼�����е�����
	int num = 0;

	vector<int>temple;
	if (this->m_Index == 1)
	{
		temple = v1;
	}
	else
	{
		temple = v2;
	}

	//��ί���
	for (vector<int>::iterator pointer = temple.begin();pointer != temple.end();pointer++)
	{
		num++;
		deque<double>judgement;
		for (int i = 0;i < 10;i++)
		{
			double judge_Score = (rand() % 401 + 600) / 10.f;
			judgement.push_back(judge_Score);
		}
		sort(judgement.begin(), judgement.end(), greater<double>());
		judgement.pop_back();
		judgement.pop_front();
		
		double sum = accumulate(judgement.begin(), judgement.end(), 0);
		double average_score = sum / (double)judgement.size();

		this->m_Speaker[*pointer].score[m_Index-1] = average_score;

		Final_List.insert(make_pair(this->m_Speaker[*pointer].score[m_Index - 1], (*pointer)));

		if (num % 6 == 0)
		{
			cout << "������������������" << num / 6 << "�����������£�����������������" << endl;
			for (multimap<double, int, greater<double>>::iterator pointer = Final_List.begin();pointer != Final_List.end();pointer++)
			{
				cout <<"��ţ�"<<pointer->second << "   ������" << this->m_Speaker[pointer->second].name << "  ������" << pointer->first << endl;
			}
			
			cout << "����������������������������������������������������������������������������" << endl;

			int count=0;
			for (multimap<double, int, greater<double>>::iterator pointer = Final_List.begin();pointer != Final_List.end() && count < 3;pointer++, count++)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back((*pointer).second);
				}
				else
				{
					this->vVictory.push_back(pointer->second);
				}
			}
			Final_List.clear();
			cout << endl;
		}
	}
	
	cout << "         ��������������������" << this->m_Index << "�ֱ���������������������������" << endl;
	
}

void Speech_Manager::show_result()
{
	
	vector<int>temp;
	if (m_Index == 1)
	{
		temp =this-> v2;
	}
	else
	{
		temp = this->vVictory;
	}
	cout << "��������������" << this->m_Index << "�ֽ���������£�������������" << endl;
	for (vector<int>::iterator pointer = temp.begin();pointer != temp.end();pointer++)
	{
		cout << " ��ţ�" << *pointer << "  ������" << this->m_Speaker[*pointer].name 
			<< "  �÷֣�" << this->m_Speaker[*pointer].score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->Show_Menu();
}

void Speech_Manager::Save_Record()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin();it != vVictory.end();it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].score [1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "������¼�ѱ���" << endl;
}

void Speech_Manager::load_Record()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsempty = true;
		ifs.close();
		return;
	}

	this->fileIsempty = false;

	ifs.putback(ch);//�������ȡ�ĵ����ַ�������

	string data;
	int index = 0;
	while (ifs >> data)
	{
		cout << data << endl;
		vector<string>v;
		int position = -1;
		int start = 0;
		while (true)
		{
			position = data.find(",", start);
			if (position == -1)
			{
				//û���ҵ������
				break;
			}
			string temp = data.substr(start, position - start);
	
			v.push_back(temp);
			start = position + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	this->fileIsempty = false;
}

void Speech_Manager::show_Record()
{
	if (this->fileIsempty == true)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Record.size();i++)
		{
			cout << "��" << i + 1 << "��" << endl;
			cout << "�ھ���ţ�" << this->m_Record[i][0] << "������" << this->m_Record[i][1] << endl;
			cout << "�Ǿ���ţ�" << this->m_Record[i][2] << "������" << this->m_Record[i][3] << endl;
			cout << "������ţ�" << this->m_Record[i][4] << "������" << this->m_Record[i][5] << endl;
		}
	}
	
}

void Speech_Manager::Clear_Record()
{
	cout << "��ȷ�������������������" << endl;
	cout << "1��ȷ�����" << endl;
	cout << "2���������" << endl;
	int choice;
	cin >> choice;
	
	if (choice == 1)
	{
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		this->initSpeaker();
		this->createSpeaker();
		this->load_Record();
		cout << "��ճɹ�" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}
