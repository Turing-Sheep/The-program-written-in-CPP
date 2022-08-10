#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<ctime>
#include<deque>
#include<string>
#include<numeric>
#include<fstream>
using namespace std;

class Speech_Manager
{
public:
	//存放12名选手
	vector<int>v1;

	//第一轮晋级容器
	vector<int>v2;

	//胜利前三名容器
	vector<int>vVictory;

	//存放编号和对应的具体选手
	//利用map容器将选手的编号和选手对应起来
	map<int, speaker>m_Speaker;

	//存放比赛的轮数
	int m_Index;
	//判断文件是否为空
	bool fileIsempty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
public:

	Speech_Manager();

	~Speech_Manager();

	void Show_Menu();

	void Exit_System();

	//初始化容器
	void initSpeaker();

	//创建选手
	void createSpeaker();

	//开始比赛
	void StartSpeech();

	//抽签
	void SpeechDraw();

	void StartCompetition();

	void show_result();

	void Save_Record();

	void load_Record();

	void show_Record();

	void Clear_Record();
};