#include<iostream>
using namespace std;
#define max 1000
#include<string>

//设计联系人结构体：姓名、性别、年龄、联系电话、家庭住址
struct person { string name;int sex; int age; string phone;string address; };

//设计通讯录结构体：联系人数组、联系人总数
struct addressbooks { struct person ad_person[max];int sum; };

void show_menu()
{
	cout << "*******************" << endl;
	cout << "*******************" << endl;
	cout << "***1、添加联系人***" << endl;
	cout << "***2、显示联系人***" << endl;
	cout << "***3、删除联系人***" << endl;
	cout << "***4、查找联系人***" << endl;
	cout << "***5、修改联系人***" << endl;
	cout << "***6、清空联系人***" << endl;
	cout << "***0、退出通讯录***" << endl;
	cout << "*******************" << endl;
	cout << "*******************" << endl;
}//将通讯录的菜单封装为函数。

void add(addressbooks* p)
{
	if (p->sum == max)
	{
		cout << "您的通讯录人数已满，无法继续添加联系人。" << endl;
		return;//退出当前函数
	}
	else
	{
		cout << "姓名： " << endl;
		cin >> p->ad_person[p->sum].name;

		cout << "性别：  " << endl;
		cout << "1——男性，2——女性" << endl;	
		while (true)//创建死循环
		{
			cin >> p->ad_person[p->sum].sex;

			if (p->ad_person[p->sum].sex == 1 || p->ad_person[p->sum].sex == 2)
			{
				break;//当用户输入1或2时，终止该死循环，继续后续内容的输入
			}
			else
			{
				cout << "您的输入有误，请重新输入。" << endl;
			}
		}

		cout << "年龄： " << endl;
		cin >> p->ad_person[p->sum].age;

		cout << "联系电话： " << endl;
		cin >> p->ad_person[p->sum].age;

		cout << "家庭住址： " << endl;
		cin >> p->ad_person[p->sum].address;
		
		p->sum++;//更新通讯录中的总人数。
		cout << "添加成功。" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏
	}	
}//创建添加联系人的函数。

void display(addressbooks* p)
{
	if (p->sum == 0) 
	{
		cout << "当前联系人列表为空，请添加联系人" << endl;
	}
	else
	{
		for (int i = 0;i < p->sum;i++)
		{
			cout << "姓名：" << p->ad_person[i].name << "\t"
				<< "性别：" << (p->ad_person[i].sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" << p->ad_person[i].age << "\t"
				<< "联系电话：" << p->ad_person[i].phone << "\t"
				<< "家庭住址：" << p->ad_person[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

int exist(addressbooks* p, string name)
{
	for (int j = 0;j < p->sum;j++)
	{
		if (p->ad_person[j].name == name)
		{
			return j;
		}
	}
	return -1;

}

int seek(addressbooks* p, string name)
{
	for (int i = 0;i < p->sum;i++)
	{
		if (p->ad_person[i].name == name)
		{
			return i;
		}
		else
		{
			return-1;
		}
	}
}

void alter(addressbooks* p, string name)
{
	seek(p, name);
	if (seek(p, name) == -1)
	{
		cout << "抱歉，未找到您要修改的联系人。" << endl;
	}
	else 
	{
		cout << "请输入修改信息：" << endl;
		cout << "姓名： " << endl;
		cin >> p->ad_person[seek(p, name)].name;

		cout << "性别：  " << endl;
		cout << "1——男性，2——女性" << endl;
		while (true)//创建死循环
		{
			cin >> p->ad_person[seek(p, name)].sex;

			if (p->ad_person[seek(p, name)].sex == 1 || p->ad_person[seek(p, name)].sex == 2)
			{
				break;//当用户输入1或2时，终止该死循环，继续后续内容的输入
			}
			else
			{
				cout << "您的输入有误，请重新输入。" << endl;
			
			}
		}

		cout << "年龄： " << endl;
		cin >> p->ad_person[seek(p, name)].age;

		cout << "联系电话： " << endl;
		cin >> p->ad_person[seek(p, name)].age;

		cout << "家庭住址： " << endl;
		cin >> p->ad_person[seek(p, name)].address;
	}
	cout << "修改成功！"<<endl;
}

void clean(addressbooks* p)
{
	cout << "请输入相应数字，确认是否清空通讯录。" << endl;
	cout << "1——确认清空" << endl;
	cout << "2——放弃清空" << endl;
	int c;
	while (true)
	{
		cin >> c;

		if (c == 1)
		{
			p->sum = 0;
			cout << "您已成功清除通讯录内容。" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (c ==2)
		{
			cout << "您已放弃清空通讯录。" << endl;
			system("pause");
			system("cls");
			break;
		}
		else 
		{
			cout << "您的输入有误，请重新输入。" << endl;

		}
	}
}

int main() 
{
	

	int num = 0;

	addressbooks ads;//创建通讯录变量
	ads.sum = 0;//将通讯录变量中的联系人数量初始化为0

	while (true)
	{
		show_menu();//调用显示菜单的函数。
		cin >> num;

		switch (num)
		{
		case 1://1、添加联系人
			add(&ads);//调用添加联系人的函数，并利用指针导入通讯录变量的地址。
			break;


		case 2://2、显示联系人
			display(&ads);
			break;


		case 3://3、删除联系人
		{	string name1;
		cout << "请输入您需要删除的联系人姓名：" << endl;
		cin >> name1;

		int n = exist(&ads, name1);
		if (n == -1)
		{
			cout << "列表中没有该联系人" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			for (int i = n;i < ads.sum;i++)
			{
				ads.ad_person[i] = ads.ad_person[i + 1];
			}
			ads.sum--;
			cout << "您已成功删除" << name1 << endl;

		}
		system("pause");
		system("cls");
		break;
		}


		case 4://4、查找联系人
		{	cout << "请输入您要查找的联系人姓名：" << endl;
		string name2;
		cin >> name2;

		if (seek(&ads, name2) == -1)
		{
			cout << "抱歉，查无此人。" << endl;
		}
		else
		{
			int s = seek(&ads, name2);
			cout << "姓名：" << ads.ad_person[s].name << "\t"
				<< "性别：" << (ads.ad_person[s].sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" <<ads.ad_person[s].age << "\t"
				<< "联系电话：" << ads.ad_person[s].phone << "\t"
				<< "家庭住址：" << ads.ad_person[s].address << endl;
		}
		system("pause");
		system("cls");
		break;
		}

		
		case 5://*5、修改联系人
		{	cout << "请输入您要修改的联系人姓名：" << endl;
		string name3;
		cin >> name3;
		alter(&ads, name3);
		system("pause");
		system("cls");
		break;
		}


		case 6://6、清空联系人
			clean(&ads);
			break;


		case 0://0、退出通讯录
		{	cout << "欢迎下次使用" << endl;
		system("pause");//按任意键继续
		return 0;//退出运行
		break;
		}
		default:
			break;
		}
	}
