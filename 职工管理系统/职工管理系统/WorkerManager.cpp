#include"WorkerManager.h"//包含头文件

//定义构造函数
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//读文件

	//文件不存在
	if (!ifs.is_open())//判断文件是否打开成功
	{
		cout << "文件不存在" << endl;
		this->m_EmpArray = NULL;//将二级指针初始化为空指针
		this->m_EmpNum = 0;//初始化文件中的员工数量
		FileIsEmpty = true;//文件为空的标志初始化为真
		ifs.close();//关闭文件
		return;//退出函数体
	}

	//文件存在，数据为空
	char ch;
	ifs >> ch;//读取文件中的一个字符，如果文件为空，则该字符也是空的
	if (ifs.eof())//eof函数为空，说明文件读完了，即文件为空
	{
		cout << "文件存在，但文件为空" << endl;
		this->FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();//关闭文件
		return;
	}

	//文件存在，数据也存在
	//统计文件中人数
	int num = this->get_EmpNum();
	cout << "职工的人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟父类指针数组所需的空间
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//将文件中的数据开辟到堆区，并且用数组中的指针标记
	this->init_Emp();
}

//定义展示菜单的函数
void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "***欢迎使用职工管理系统***" << endl;
	cout << "*****0、退出管理程序******" << endl;
	cout << "*****1、增加职工信息******" << endl;
	cout << "*****2、显示职工信息******" << endl;
	cout << "*****3、删除离职职工******" << endl;
	cout << "*****4、修改职工信息******" << endl;
	cout << "*****5、查找职工信息******" << endl;
	cout << "*****6、查找编号排序******" << endl;
	cout << "*****7、清空所有文档******" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

//定义退出系统的函数
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");//按任意键继续
	exit(0);//退出程序的函数
}

//定义添加职工的函数
void WorkerManager::Add_num()
{
	cout << "请输入加入职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算添加空间的大小.创建父类指针的数组
		int NewSize = addNum + this->m_EmpNum;
		worker** NewSpace = new worker * [NewSize];

		//将原来的空间下的数据拷贝到新空间下。
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				NewSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新的数据
		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int select;
			A:
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			for (int j = 0;j < this->m_EmpNum;j++)
			{
				if (this->m_EmpArray[i]->m_Id == id)
				{
					cout << "您输入的员工编号已存在，请重新输入：" << endl;
					goto A;
					break;
				}
			}
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			B:
			cout << "请选择该员工的职位：" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> select;
			//根据用户的输入情况在堆区开辟相应对象
			switch (select)
			{
			case 1:
				NewSpace[i + this->m_EmpNum] = new Employee(id, name, 1);
				break;
			case 2:
				NewSpace[i + this->m_EmpNum] = new Manager(id, name, 2);
				break;
			case 3:
				NewSpace[i + this->m_EmpNum] = new boss(id, name, 3);
				break;
			default:
				cout << "您的输入有误！" << endl;
				goto B;//利用goto 语句让用户重新输入
				break;

			}
			
		}
		cout << "您已经成功添加" << addNum << "名员工。" << endl;
		//添加过后，更新当前数据：
		this->m_EmpNum = NewSize;
		//释放原有的保存父类指针的数组空间
		delete[]this->m_EmpArray;
		//更新二级指针的指向，指向新的父类指针
		this->m_EmpArray = NewSpace;
		this->save();
		this->FileIsEmpty = false;
	}
	else
	{
		cout << "您的输入有误" << endl;
	}

	system("pause");//按任意键继续
	system("cls");//清屏
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件——写文件
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId
			<< endl;
	}
	ofs.close();
}

//统计文件中的人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;//用于储存从文件中读取的序号
	string name;//用于储存从文件中读取的姓名
	int did;//储存文件中读取的岗位

	int num=0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//初始化数组
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;

	int num=0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		switch (did)
		{
		case 1:
			this->m_EmpArray[num] = new Employee(id, name, did);
			break;
		case 2:
			this->m_EmpArray[num] = new Manager(id, name, did);
			break;
		case 3:
			this->m_EmpArray[num] = new boss(id,name, did);
			break;
		default:
			break;
		}
			num++;
	}
	ifs.close();
}

//显示职工
void WorkerManager:: Show_Emp()
{
	if (this->m_EmpNum==0)
	{
		cout << "文件不存在或者文件信息为空" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{
			//利用指针找到具体的对象中的成员函数
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在并删除
void WorkerManager::Is_Exist()
{
	int A = -1;
	string name;
	cout << "请输入将被删除的员工姓名：" << endl;
	cin >> name;

	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			cout << "成功找到该员工:" << endl;
			this->m_EmpArray[i]->showinfo();
			A = 1;
			cout << endl;

			cout << "若确认删除，请输入该员工的编号：" << endl;
			cout << "（输出其余数字则放弃删除。）" << endl;
			int B = 0;
			cin >> B;

			if (this->m_EmpArray[i]->m_Id == B && this->m_EmpArray[i]->m_Name == name)
			{
				for (int i = 0;i < this->m_EmpNum-B;i++)
				{
					this->m_EmpArray[B - 1 + i] = this->m_EmpArray[B + i];
				}

				this->m_EmpNum--;
				this->save();
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "您已放弃删除该员工。" << endl;
				break;
			}
		}
	}
	if (A == -1)
	{
		cout << "该员工不存在" << endl;
	}
	system("pause");
	system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
	cout << "请输入您需要修改的员工姓名：" << endl;
	string name;
	cin >> name;
	
	int A = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			cout << "该员工信息如下：" << endl;
			this->m_EmpArray[i]->showinfo();
			A = 1;
			delete this->m_EmpArray[i];
			cout << "请重新输入该员工信息：" << endl;
			int id;
			string name;
			int did;

			cout << "请输入修改后的姓名：" << endl;
			cin >> name;

			cout << "请输入修改后的员工编号：" << endl;
			cin >> id;

			B:
			cout << "请输入修改后的部门编号：" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			
			switch (did)
			{
			case 1:
				this->m_EmpArray[i] = new Employee(id, name, did);
				break;
			case 2:
				this->m_EmpArray[i] = new Manager(id, name, did);
				break;
			case 3:
				this->m_EmpArray[i] = new boss(id, name, did);
				break;
			default:
				cout << "您的选择有误，请重新选择。" << endl;
				goto B;
				break;
			}
			cout << "修改成功！" << endl;
			break;
		}
	}

	this->save();
	if(A!=1)
	{
		cout << "未找到该员工。" << endl;
	}
	system("pause");
	system("cls");
}

//查找职工信息
void WorkerManager:: Find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者文件为空！" << endl;
	
	}
	else
	{

		cout << "请输入您需要查找的方式：" << endl;
		cout << "1、通过职工编号查询。" << endl
			<< "2、通过职工姓名查询。" << endl;
		int choice;
		cin >> choice;
		switch(choice)
		{
		case 1:
		{cout << "请输入您查找职工的编号：" << endl;
		int NUM;
		cin >> NUM;
		int A = 0;
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]->m_Id == NUM)
			{
				cout << "查到此人，此人信息如下：" << endl;
				this->m_EmpArray[i]->showinfo();
				int A = 1;
			
			}
		}
		if (A != 1)
		{
			cout << "未查到此人" << endl;
		}
		}
			break;
		case 2:
		{	cout << "请输入您查找职工的姓名：" << endl;
		string F_name;
		cin >> F_name;
		int B = 0;
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]->m_Name == F_name)
			{
				cout << "查到此人，此人信息如下：" << endl;
				this->m_EmpArray[i]->showinfo();
				int B = 1;
			}
		}
		if (B != 1)
		{
			cout << "未查到此人。" << endl;
		}
		break;
		}
		default:
			cout << "您的选择有误！" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//员工排序
void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、升序排列。" << endl;
		cout << "2、降序排列。" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				int max = i;

				for (int j = i+1;j < this->m_EmpNum;j++)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						max = j;
					}
				
				}
				if (max != i)
				{
					worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[max];
					this->m_EmpArray[max] = temp;
				}
				
				
			}
			cout << "排序成功，信息如下：" << endl;
			this->Show_Emp();
		}
		else if(choice==2)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				int min = i;

				for (int j = i+1;j < this->m_EmpNum;j++)
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						min = j;
					}

				}
				if (min != i)
				{
					worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[min];
					this->m_EmpArray[min] = temp;
				}


			}
			cout << "排序成功，信息如下：" << endl;
			this->Show_Emp();
		}
		else
		{
			cout << "您的输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空文档
void WorkerManager::Clean_File()
{
	cout << "请确认清空文件" << endl;
	cout << "1、清空" << endl;
	cout << "2、返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < m_EmpNum;i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[]this->m_EmpArray;
			this->m_EmpNum = 0;
			this->FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	else
	{
		
	}
	system("pause");
	system("cls");
}
//定义析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		m_EmpArray = NULL;
	}

}