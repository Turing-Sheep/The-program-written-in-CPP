#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//���������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�������ռ�
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "information"

class WorkerManager
{
	//����Ȩ��
public:
	//WorkerManager�Ĺ��캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ��
	void Add_num();
	int m_EmpNum;//��¼��ǰϵͳ�ڵ�ְ������
	worker**m_EmpArray;//��������ָ�룬ָ�������ְ��һ��ָ������

	//�����ļ�
	void save();

	//��ȡ�ļ�
	bool FileIsEmpty;//�ļ�Ϊ�յı�־


	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ������ָ�����飬��������
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//�ж�ְ���Ƿ���ڲ�ɾ��
	void Is_Exist();

	//�޸�Ա����Ϣ
	void Mod_Emp();

	//����Ա����Ϣ
	void Find_Emp();

	//��Ա����Ϣ��������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//WorkerManager����������
	~WorkerManager();
};