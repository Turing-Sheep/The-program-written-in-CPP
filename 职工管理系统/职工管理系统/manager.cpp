#include"manager.h"

//���¶��徭�����е��вι��캯��
Manager::Manager(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

//�ض��徭�����е��麯����չʾ������Ϣ
 void Manager::showinfo()
{
	 cout << "ְ����ţ�" << this->m_Id
		 << "\tְ��������" << this->m_Name
		 << "\t��λ��ţ�" << this->m_DeptId
		 << "\t��λְ������ϰ彻����������Ա����������"
		 << endl;
 }

 //���¶��徭�����е��麯������ȡ��������
 string Manager::getDeptName()
 {
	 return string("����");
 }