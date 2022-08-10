#include"manager.h"

//重新定义经理类中的有参构造函数
Manager::Manager(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

//重定义经理类中的虚函数：展示个人信息
 void Manager::showinfo()
{
	 cout << "职工编号：" << this->m_Id
		 << "\t职工姓名：" << this->m_Name
		 << "\t岗位编号：" << this->m_DeptId
		 << "\t岗位职责：完成老板交给的任务，向员工发布任务。"
		 << endl;
 }

 //重新定义经理类中的虚函数：获取部门名称
 string Manager::getDeptName()
 {
	 return string("经理");
 }