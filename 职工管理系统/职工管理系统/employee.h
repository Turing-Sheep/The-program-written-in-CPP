#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//创建子类普通员工并继承父类
class Employee :public worker
{
	//访问权限
	public:
		//声明有参构造函数
		Employee(int id,string name,int dId);

		//声明基类中需要重新定义的函数（virtual可以删可以不删）
		virtual void showinfo();

		//声明基类中需要重新定义的函数
		virtual string getDeptName();

};