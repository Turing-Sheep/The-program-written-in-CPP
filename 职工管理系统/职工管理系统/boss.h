#pragma once
using namespace std;
#include<iostream>
#include"worker.h"

//创建老板类，并且继承抽象基类
class boss :public worker
{
//访问权限
public:
	//声明有参构造函数
	boss(int id, string name, int dId);

	//声明重定义的函数：显示个人信息
	virtual void showinfo();

	//声明重定义的函数，获取岗位名称
	virtual string getDeptName();
};