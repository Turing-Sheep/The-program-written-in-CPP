#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

//创建经理类,并且继承父类
class Manager :public worker
{
//访问权限
public:
	//声明经理类的有参构造函数
	Manager(int id,string name,int dId);

	//声明重定义的父类中的纯虚函数：显示个人信息
	virtual void showinfo();

	//声明重定义的父类中的纯虚函数：或许岗位名称
	virtual string getDeptName();
};