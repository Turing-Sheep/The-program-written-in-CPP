#pragma once
#include<iostream>
using namespace std;
#include<string>

//��������
class worker
{
//��Ա���Եķ���Ȩ��
public:
	//ְ�����
	int m_Id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DeptId;

//��Ա��Ϊ�ķ���Ȩ��
public:
	//��ʾ������Ϣ����������Ĵ��麯��
	virtual void showinfo() = 0;

	//��ȡ��λ���ƣ���������Ĵ��麯��
	virtual string getDeptName() = 0;
};