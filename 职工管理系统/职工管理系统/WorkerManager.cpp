#include"WorkerManager.h"//����ͷ�ļ�

//���幹�캯��
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ�

	//�ļ�������
	if (!ifs.is_open())//�ж��ļ��Ƿ�򿪳ɹ�
	{
		cout << "�ļ�������" << endl;
		this->m_EmpArray = NULL;//������ָ���ʼ��Ϊ��ָ��
		this->m_EmpNum = 0;//��ʼ���ļ��е�Ա������
		FileIsEmpty = true;//�ļ�Ϊ�յı�־��ʼ��Ϊ��
		ifs.close();//�ر��ļ�
		return;//�˳�������
	}

	//�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;//��ȡ�ļ��е�һ���ַ�������ļ�Ϊ�գ�����ַ�Ҳ�ǿյ�
	if (ifs.eof())//eof����Ϊ�գ�˵���ļ������ˣ����ļ�Ϊ��
	{
		cout << "�ļ����ڣ����ļ�Ϊ��" << endl;
		this->FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();//�ر��ļ�
		return;
	}

	//�ļ����ڣ�����Ҳ����
	//ͳ���ļ�������
	int num = this->get_EmpNum();
	cout << "ְ��������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٸ���ָ����������Ŀռ�
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//���ļ��е����ݿ��ٵ������������������е�ָ����
	this->init_Emp();
}

//����չʾ�˵��ĺ���
void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << "***��ӭʹ��ְ������ϵͳ***" << endl;
	cout << "*****0���˳��������******" << endl;
	cout << "*****1������ְ����Ϣ******" << endl;
	cout << "*****2����ʾְ����Ϣ******" << endl;
	cout << "*****3��ɾ����ְְ��******" << endl;
	cout << "*****4���޸�ְ����Ϣ******" << endl;
	cout << "*****5������ְ����Ϣ******" << endl;
	cout << "*****6�����ұ������******" << endl;
	cout << "*****7����������ĵ�******" << endl;
	cout << "**************************" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

//�����˳�ϵͳ�ĺ���
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");//�����������
	exit(0);//�˳�����ĺ���
}

//�������ְ���ĺ���
void WorkerManager::Add_num()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//������ӿռ�Ĵ�С.��������ָ�������
		int NewSize = addNum + this->m_EmpNum;
		worker** NewSpace = new worker * [NewSize];

		//��ԭ���Ŀռ��µ����ݿ������¿ռ��¡�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				NewSpace[i] = this->m_EmpArray[i];
			}
		}

		//����µ�����
		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int select;
			A:
			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			for (int j = 0;j < this->m_EmpNum;j++)
			{
				if (this->m_EmpArray[i]->m_Id == id)
				{
					cout << "�������Ա������Ѵ��ڣ����������룺" << endl;
					goto A;
					break;
				}
			}
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			B:
			cout << "��ѡ���Ա����ְλ��" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> select;
			//�����û�����������ڶ���������Ӧ����
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
				cout << "������������" << endl;
				goto B;//����goto ������û���������
				break;

			}
			
		}
		cout << "���Ѿ��ɹ����" << addNum << "��Ա����" << endl;
		//��ӹ��󣬸��µ�ǰ���ݣ�
		this->m_EmpNum = NewSize;
		//�ͷ�ԭ�еı��游��ָ�������ռ�
		delete[]this->m_EmpArray;
		//���¶���ָ���ָ��ָ���µĸ���ָ��
		this->m_EmpArray = NewSpace;
		this->save();
		this->FileIsEmpty = false;
	}
	else
	{
		cout << "������������" << endl;
	}

	system("pause");//�����������
	system("cls");//����
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�����д�ļ�
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId
			<< endl;
	}
	ofs.close();
}

//ͳ���ļ��е�����
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;//���ڴ�����ļ��ж�ȡ�����
	string name;//���ڴ�����ļ��ж�ȡ������
	int did;//�����ļ��ж�ȡ�ĸ�λ

	int num=0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//��ʼ������
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

//��ʾְ��
void WorkerManager:: Show_Emp()
{
	if (this->m_EmpNum==0)
	{
		cout << "�ļ������ڻ����ļ���ϢΪ��" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNum;i++)
		{
			//����ָ���ҵ�����Ķ����еĳ�Ա����
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڲ�ɾ��
void WorkerManager::Is_Exist()
{
	int A = -1;
	string name;
	cout << "�����뽫��ɾ����Ա��������" << endl;
	cin >> name;

	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			cout << "�ɹ��ҵ���Ա��:" << endl;
			this->m_EmpArray[i]->showinfo();
			A = 1;
			cout << endl;

			cout << "��ȷ��ɾ�����������Ա���ı�ţ�" << endl;
			cout << "������������������ɾ������" << endl;
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
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "���ѷ���ɾ����Ա����" << endl;
				break;
			}
		}
	}
	if (A == -1)
	{
		cout << "��Ա��������" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	cout << "����������Ҫ�޸ĵ�Ա��������" << endl;
	string name;
	cin >> name;
	
	int A = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			cout << "��Ա����Ϣ���£�" << endl;
			this->m_EmpArray[i]->showinfo();
			A = 1;
			delete this->m_EmpArray[i];
			cout << "�����������Ա����Ϣ��" << endl;
			int id;
			string name;
			int did;

			cout << "�������޸ĺ��������" << endl;
			cin >> name;

			cout << "�������޸ĺ��Ա����ţ�" << endl;
			cin >> id;

			B:
			cout << "�������޸ĺ�Ĳ��ű�ţ�" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
				cout << "����ѡ������������ѡ��" << endl;
				goto B;
				break;
			}
			cout << "�޸ĳɹ���" << endl;
			break;
		}
	}

	this->save();
	if(A!=1)
	{
		cout << "δ�ҵ���Ա����" << endl;
	}
	system("pause");
	system("cls");
}

//����ְ����Ϣ
void WorkerManager:: Find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	
	}
	else
	{

		cout << "����������Ҫ���ҵķ�ʽ��" << endl;
		cout << "1��ͨ��ְ����Ų�ѯ��" << endl
			<< "2��ͨ��ְ��������ѯ��" << endl;
		int choice;
		cin >> choice;
		switch(choice)
		{
		case 1:
		{cout << "������������ְ���ı�ţ�" << endl;
		int NUM;
		cin >> NUM;
		int A = 0;
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]->m_Id == NUM)
			{
				cout << "�鵽���ˣ�������Ϣ���£�" << endl;
				this->m_EmpArray[i]->showinfo();
				int A = 1;
			
			}
		}
		if (A != 1)
		{
			cout << "δ�鵽����" << endl;
		}
		}
			break;
		case 2:
		{	cout << "������������ְ����������" << endl;
		string F_name;
		cin >> F_name;
		int B = 0;
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]->m_Name == F_name)
			{
				cout << "�鵽���ˣ�������Ϣ���£�" << endl;
				this->m_EmpArray[i]->showinfo();
				int B = 1;
			}
		}
		if (B != 1)
		{
			cout << "δ�鵽���ˡ�" << endl;
		}
		break;
		}
		default:
			cout << "����ѡ������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//Ա������
void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1���������С�" << endl;
		cout << "2���������С�" << endl;
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
			cout << "����ɹ�����Ϣ���£�" << endl;
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
			cout << "����ɹ�����Ϣ���£�" << endl;
			this->Show_Emp();
		}
		else
		{
			cout << "������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ĵ�
void WorkerManager::Clean_File()
{
	cout << "��ȷ������ļ�" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ����ؽ�
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
		cout << "��ճɹ���" << endl;
	}
	else
	{
		
	}
	system("pause");
	system("cls");
}
//������������
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