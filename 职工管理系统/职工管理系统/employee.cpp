#include"employee.h"

//���幹�캯��
Employee::Employee(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//������ʾ������Ϣ�ĺ���
void Employee::showinfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��ţ�" << this->m_DeptId
		<< "\t��λְ����ɾ�����������" << endl;
}

//�����ȡ��λ���Ƶĺ���
string Employee::getDeptName()
{
	return string("Ա��");
}