#pragma once
using namespace std;
#include<iostream>
#include"worker.h"

//�����ϰ��࣬���Ҽ̳г������
class boss :public worker
{
//����Ȩ��
public:
	//�����вι��캯��
	boss(int id, string name, int dId);

	//�����ض���ĺ�������ʾ������Ϣ
	virtual void showinfo();

	//�����ض���ĺ�������ȡ��λ����
	virtual string getDeptName();
};