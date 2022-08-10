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
	cout << "欢迎使用演讲比赛管理系统！" << endl;
	cout << "1、开始演讲比赛" << endl;
	cout << "2、查看往届记录" << endl;
	cout << "3、清空比赛记录" << endl;
	cout << "4、退出比赛程序" << endl;

}

void Speech_Manager::Exit_System()
{
	cout << "欢迎下次使用" << endl;
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
		string name = "选手";
		name += nameSeed[i];

		speaker sp;
		sp.name = name;

		for (int j = 0;j < 2;j++)
		{
			sp.score[j] = 0;
		}

		//创建选手的编号，并且放入到V1容器中
		this->v1.push_back(i + 10001);

		//选手的编号和选手放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void Speech_Manager::StartSpeech()
{
	//第一轮开始比赛

	//1、抽签
	this->SpeechDraw();
	system("pause");
	//2、比赛
	this->StartCompetition();
	system("pause");
	//3、显示晋级的结果
	this->show_result();

	//第二轮比赛开始
	this->m_Index++;
	//1、抽签
	this->SpeechDraw();
	system("pause");
	//2、比赛
	this->StartCompetition();
	system("pause");
	//3、显示最终的结果
	this->show_result();
	Save_Record();
	cout << "本次比赛完毕！" << endl;
	this->initSpeaker();
	this->createSpeaker();
	this->load_Record();
}

void Speech_Manager::SpeechDraw()
{
	srand((unsigned int)time(NULL));
	cout << "          第" << this->m_Index << "轮比赛选手正在抽签" << endl;
	cout << "_______________________________________________________________" << endl;
	cout << endl;
	cout << "抽签后的顺序如下：" << endl;
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
	cout << "           ——————第" << this->m_Index << "轮比赛开始——————" << endl;
	
	//创建一个容器记录选手的分数和编号，公布成绩
	multimap<double, int, greater<double>>Final_List;
	//记录容器中的人数
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

	//评委打分
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
			cout << "————————第" << num / 6 << "组比赛结果如下：————————" << endl;
			for (multimap<double, int, greater<double>>::iterator pointer = Final_List.begin();pointer != Final_List.end();pointer++)
			{
				cout <<"编号："<<pointer->second << "   姓名：" << this->m_Speaker[pointer->second].name << "  分数：" << pointer->first << endl;
			}
			
			cout << "——————————————————————————————————————" << endl;

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
	
	cout << "         —————————第" << this->m_Index << "轮比赛结束——————————" << endl;
	
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
	cout << "——————第" << this->m_Index << "轮晋级结果如下：——————" << endl;
	for (vector<int>::iterator pointer = temp.begin();pointer != temp.end();pointer++)
	{
		cout << " 编号：" << *pointer << "  姓名：" << this->m_Speaker[*pointer].name 
			<< "  得分：" << this->m_Speaker[*pointer].score[m_Index - 1] << endl;
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
	cout << "比赛记录已保存" << endl;
}

void Speech_Manager::load_Record()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsempty = true;
		ifs.close();
		return;
	}

	this->fileIsempty = false;

	ifs.putback(ch);//将上面读取的单个字符读回来

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
				//没有找到的情况
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
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Record.size();i++)
		{
			cout << "第" << i + 1 << "届" << endl;
			cout << "冠军编号：" << this->m_Record[i][0] << "分数：" << this->m_Record[i][1] << endl;
			cout << "亚军编号：" << this->m_Record[i][2] << "分数：" << this->m_Record[i][3] << endl;
			cout << "季军编号：" << this->m_Record[i][4] << "分数：" << this->m_Record[i][5] << endl;
		}
	}
	
}

void Speech_Manager::Clear_Record()
{
	cout << "您确定清空往届所有数据吗？" << endl;
	cout << "1、确定清空" << endl;
	cout << "2、放弃清空" << endl;
	int choice;
	cin >> choice;
	
	if (choice == 1)
	{
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		this->initSpeaker();
		this->createSpeaker();
		this->load_Record();
		cout << "清空成功" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}
