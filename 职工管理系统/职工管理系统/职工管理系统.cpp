#include"WorkerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

//���Ը���ְλ����Ϣ��ʾ��
void test_class()
{
	//���ø���ָ��ָ�������ڶ������ٵ��ڴ�
	worker* p1 = new Employee(1,"����",1);
	p1->showinfo();
	delete p1;

	p1= new boss(1, "����", 1);
	p1->showinfo();
	delete p1;

	p1= new Manager(1, "����", 1);
	p1->showinfo();
	delete p1;
}

//ְ������ϵͳ
int app()
{
	//ʵ���������߶���
	WorkerManager wm;
	int choice;

	//����һ����ѭ��
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Show_Menu();

		cout << "����������ѡ��" << endl;
		
		cin >> choice;//�����û���ѡ��

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.Add_num();
			
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;

		case 3://ɾ��ְ��
			wm.Is_Exist();
			break;

		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;

		case 5://����ְ��
			wm.Find_Emp();
			break;

		case 6://����ְ��
			wm.Sort_Emp();
			break;

		case 7://����ļ�
			wm.Clean_File();
			break;

		default:
			cout << "������������" << endl;
			system("pause");//�����������
			system("cls");//����
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