#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流的头文件
using namespace std;//使用标准的命名空间
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "information"

class WorkerManager
{
	//访问权限
public:
	//WorkerManager的构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//添加职工
	void Add_num();
	int m_EmpNum;//记录当前系统内的职工人数
	worker**m_EmpArray;//创建二级指针，指向堆区的职工一级指针数组

	//保存文件
	void save();

	//读取文件
	bool FileIsEmpty;//文件为空的标志


	//统计文件中的人数
	int get_EmpNum();

	//初始化父类指针数组，开辟数据
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//判断职工是否存在并删除
	void Is_Exist();

	//修改员工信息
	void Mod_Emp();

	//查找员工信息
	void Find_Emp();

	//将员工信息进行排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//WorkerManager的析构函数
	~WorkerManager();
};