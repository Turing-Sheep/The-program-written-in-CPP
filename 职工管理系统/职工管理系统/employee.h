#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//����������ͨԱ�����̳и���
class Employee :public worker
{
	//����Ȩ��
	public:
		//�����вι��캯��
		Employee(int id,string name,int dId);

		//������������Ҫ���¶���ĺ�����virtual����ɾ���Բ�ɾ��
		virtual void showinfo();

		//������������Ҫ���¶���ĺ���
		virtual string getDeptName();

};