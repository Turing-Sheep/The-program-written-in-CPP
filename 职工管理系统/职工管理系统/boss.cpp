#include"boss.h"

//�ض��幹�캯��
boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//���¶����ϰ����еĴ��麯����չʾ������Ϣ
void boss::showinfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��ţ�" << this->m_DeptId
		<< "\t��λְ�𣺹���˾�е���������" << endl;
}

//�����ȡ��λ���Ƶĺ���
string boss::getDeptName()
{
	return string("�ϰ�");
}