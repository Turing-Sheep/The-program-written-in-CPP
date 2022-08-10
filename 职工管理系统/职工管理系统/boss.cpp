#include"boss.h"

//重定义构造函数
boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//重新定义老板类中的纯虚函数：展示个人信息
void boss::showinfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位编号：" << this->m_DeptId
		<< "\t岗位职责：管理公司中的所有事务。" << endl;
}

//定义获取岗位名称的函数
string boss::getDeptName()
{
	return string("老板");
}