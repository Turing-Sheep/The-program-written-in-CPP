#pragma once
#include<iostream>
using namespace std;
#include<string>

//搭建抽象基类
class worker
{
//成员属性的访问权限
public:
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;

//成员行为的访问权限
public:
	//显示个人信息：声明父类的纯虚函数
	virtual void showinfo() = 0;

	//获取岗位名称：声明父类的纯虚函数
	virtual string getDeptName() = 0;
};