#include"employee.h"

//定义构造函数
Employee::Employee(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//定义显示个人信息的函数
void Employee::showinfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位编号：" << this->m_DeptId
		<< "\t岗位职责：完成经理交给的任务。" << endl;
}

//定义获取岗位名称的函数
string Employee::getDeptName()
{
	return string("员工");
}