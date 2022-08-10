#include"WorkerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

//测试各个职位的信息显示。
void test_class()
{
	//利用父类指针指向子类在堆区开辟的内存
	worker* p1 = new Employee(1,"张三",1);
	p1->showinfo();
	delete p1;

	p1= new boss(1, "杨五", 1);
	p1->showinfo();
	delete p1;

	p1= new Manager(1, "李四", 1);
	p1->showinfo();
	delete p1;
}

//职工管理系统
int app()
{
	//实例化管理者对象
	WorkerManager wm;
	int choice;

	//创建一个死循环
	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择" << endl;
		
		cin >> choice;//接受用户的选择

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.Add_num();
			
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;

		case 3://删除职工
			wm.Is_Exist();
			break;

		case 4://修改职工
			wm.Mod_Emp();
			break;

		case 5://查找职工
			wm.Find_Emp();
			break;

		case 6://排序职工
			wm.Sort_Emp();
			break;

		case 7://清空文件
			wm.Clean_File();
			break;

		default:
			cout << "您的输入有误！" << endl;
			system("pause");//按任意键继续
			system("cls");//清屏
			break;
		}

	}
	system("pause");
	return 0;
}

int main()
{
	app();
	system("pause");
	return 0;
}