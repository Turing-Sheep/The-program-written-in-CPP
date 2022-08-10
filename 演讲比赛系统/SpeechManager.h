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
	//���12��ѡ��
	vector<int>v1;

	//��һ�ֽ�������
	vector<int>v2;

	//ʤ��ǰ��������
	vector<int>vVictory;

	//��ű�źͶ�Ӧ�ľ���ѡ��
	//����map������ѡ�ֵı�ź�ѡ�ֶ�Ӧ����
	map<int, speaker>m_Speaker;

	//��ű���������
	int m_Index;
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsempty;
	//��������¼������
	map<int, vector<string>>m_Record;
public:

	Speech_Manager();

	~Speech_Manager();

	void Show_Menu();

	void Exit_System();

	//��ʼ������
	void initSpeaker();

	//����ѡ��
	void createSpeaker();

	//��ʼ����
	void StartSpeech();

	//��ǩ
	void SpeechDraw();

	void StartCompetition();

	void show_result();

	void Save_Record();

	void load_Record();

	void show_Record();

	void Clear_Record();
};