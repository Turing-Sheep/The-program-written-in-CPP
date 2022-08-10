#include<iostream>
using namespace std;
#define max 1000
#include<string>

//�����ϵ�˽ṹ�壺�������Ա����䡢��ϵ�绰����ͥסַ
struct person { string name;int sex; int age; string phone;string address; };

//���ͨѶ¼�ṹ�壺��ϵ�����顢��ϵ������
struct addressbooks { struct person ad_person[max];int sum; };

void show_menu()
{
	cout << "*******************" << endl;
	cout << "*******************" << endl;
	cout << "***1�������ϵ��***" << endl;
	cout << "***2����ʾ��ϵ��***" << endl;
	cout << "***3��ɾ����ϵ��***" << endl;
	cout << "***4��������ϵ��***" << endl;
	cout << "***5���޸���ϵ��***" << endl;
	cout << "***6�������ϵ��***" << endl;
	cout << "***0���˳�ͨѶ¼***" << endl;
	cout << "*******************" << endl;
	cout << "*******************" << endl;
}//��ͨѶ¼�Ĳ˵���װΪ������

void add(addressbooks* p)
{
	if (p->sum == max)
	{
		cout << "����ͨѶ¼�����������޷����������ϵ�ˡ�" << endl;
		return;//�˳���ǰ����
	}
	else
	{
		cout << "������ " << endl;
		cin >> p->ad_person[p->sum].name;

		cout << "�Ա�  " << endl;
		cout << "1�������ԣ�2����Ů��" << endl;	
		while (true)//������ѭ��
		{
			cin >> p->ad_person[p->sum].sex;

			if (p->ad_person[p->sum].sex == 1 || p->ad_person[p->sum].sex == 2)
			{
				break;//���û�����1��2ʱ����ֹ����ѭ���������������ݵ�����
			}
			else
			{
				cout << "���������������������롣" << endl;
			}
		}

		cout << "���䣺 " << endl;
		cin >> p->ad_person[p->sum].age;

		cout << "��ϵ�绰�� " << endl;
		cin >> p->ad_person[p->sum].age;

		cout << "��ͥסַ�� " << endl;
		cin >> p->ad_person[p->sum].address;
		
		p->sum++;//����ͨѶ¼�е���������
		cout << "��ӳɹ���" << endl;

		system("pause");//�밴���������
		system("cls");//����
	}	
}//���������ϵ�˵ĺ�����

void display(addressbooks* p)
{
	if (p->sum == 0) 
	{
		cout << "��ǰ��ϵ���б�Ϊ�գ��������ϵ��" << endl;
	}
	else
	{
		for (int i = 0;i < p->sum;i++)
		{
			cout << "������" << p->ad_person[i].name << "\t"
				<< "�Ա�" << (p->ad_person[i].sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" << p->ad_person[i].age << "\t"
				<< "��ϵ�绰��" << p->ad_person[i].phone << "\t"
				<< "��ͥסַ��" << p->ad_person[i].address << endl;
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
		cout << "��Ǹ��δ�ҵ���Ҫ�޸ĵ���ϵ�ˡ�" << endl;
	}
	else 
	{
		cout << "�������޸���Ϣ��" << endl;
		cout << "������ " << endl;
		cin >> p->ad_person[seek(p, name)].name;

		cout << "�Ա�  " << endl;
		cout << "1�������ԣ�2����Ů��" << endl;
		while (true)//������ѭ��
		{
			cin >> p->ad_person[seek(p, name)].sex;

			if (p->ad_person[seek(p, name)].sex == 1 || p->ad_person[seek(p, name)].sex == 2)
			{
				break;//���û�����1��2ʱ����ֹ����ѭ���������������ݵ�����
			}
			else
			{
				cout << "���������������������롣" << endl;
			
			}
		}

		cout << "���䣺 " << endl;
		cin >> p->ad_person[seek(p, name)].age;

		cout << "��ϵ�绰�� " << endl;
		cin >> p->ad_person[seek(p, name)].age;

		cout << "��ͥסַ�� " << endl;
		cin >> p->ad_person[seek(p, name)].address;
	}
	cout << "�޸ĳɹ���"<<endl;
}

void clean(addressbooks* p)
{
	cout << "��������Ӧ���֣�ȷ���Ƿ����ͨѶ¼��" << endl;
	cout << "1����ȷ�����" << endl;
	cout << "2�����������" << endl;
	int c;
	while (true)
	{
		cin >> c;

		if (c == 1)
		{
			p->sum = 0;
			cout << "���ѳɹ����ͨѶ¼���ݡ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (c ==2)
		{
			cout << "���ѷ������ͨѶ¼��" << endl;
			system("pause");
			system("cls");
			break;
		}
		else 
		{
			cout << "���������������������롣" << endl;

		}
	}
}

int main() 
{
	

	int num = 0;

	addressbooks ads;//����ͨѶ¼����
	ads.sum = 0;//��ͨѶ¼�����е���ϵ��������ʼ��Ϊ0

	while (true)
	{
		show_menu();//������ʾ�˵��ĺ�����
		cin >> num;

		switch (num)
		{
		case 1://1�������ϵ��
			add(&ads);//���������ϵ�˵ĺ�����������ָ�뵼��ͨѶ¼�����ĵ�ַ��
			break;


		case 2://2����ʾ��ϵ��
			display(&ads);
			break;


		case 3://3��ɾ����ϵ��
		{	string name1;
		cout << "����������Ҫɾ������ϵ��������" << endl;
		cin >> name1;

		int n = exist(&ads, name1);
		if (n == -1)
		{
			cout << "�б���û�и���ϵ��" << endl;
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
			cout << "���ѳɹ�ɾ��" << name1 << endl;

		}
		system("pause");
		system("cls");
		break;
		}


		case 4://4��������ϵ��
		{	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
		string name2;
		cin >> name2;

		if (seek(&ads, name2) == -1)
		{
			cout << "��Ǹ�����޴��ˡ�" << endl;
		}
		else
		{
			int s = seek(&ads, name2);
			cout << "������" << ads.ad_person[s].name << "\t"
				<< "�Ա�" << (ads.ad_person[s].sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" <<ads.ad_person[s].age << "\t"
				<< "��ϵ�绰��" << ads.ad_person[s].phone << "\t"
				<< "��ͥסַ��" << ads.ad_person[s].address << endl;
		}
		system("pause");
		system("cls");
		break;
		}

		
		case 5://*5���޸���ϵ��
		{	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
		string name3;
		cin >> name3;
		alter(&ads, name3);
		system("pause");
		system("cls");
		break;
		}


		case 6://6�������ϵ��
			clean(&ads);
			break;


		case 0://0���˳�ͨѶ¼
		{	cout << "��ӭ�´�ʹ��" << endl;
		system("pause");//�����������
		return 0;//�˳�����
		break;
		}
		default:
			break;
		}
	}
