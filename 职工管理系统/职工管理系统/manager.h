#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

//����������,���Ҽ̳и���
class Manager :public worker
{
//����Ȩ��
public:
	//������������вι��캯��
	Manager(int id,string name,int dId);

	//�����ض���ĸ����еĴ��麯������ʾ������Ϣ
	virtual void showinfo();

	//�����ض���ĸ����еĴ��麯���������λ����
	virtual string getDeptName();
};