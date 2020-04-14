#include "WorkerManager.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include<cstdlib>
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//����ļ�Ϊ��
	if (!ifs.is_open()) {
		cout << "empty" << endl;//���Դ���
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		cout << "ְ������Ϊ0" << endl;
		return;
	}
	//�ļ����ڣ�����¼����
	int num = this->getNum();
	cout << "��ǰְ��������" << num << endl;//���Դ���
	this->m_EmpNum = num;

	//���ļ������ݴ浽����
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	
	

}
WorkerManager::~WorkerManager() {
	if (m_EmpArray != NULL) {
		delete[] m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************************************" << endl;
	cout << "*********************��ӭʹ��ְ������ϵͳ************************" << endl;
	cout << "*********************0���˳��������******************************" << endl;
	cout << "*********************1������ְ����Ϣ******************************" << endl;
	cout << "*********************2����ʾְ����Ϣ******************************" << endl;
	cout << "*********************3��ɾ��ְ����Ϣ******************************" << endl;
	cout << "*********************4���޸�ְ����Ϣ******************************" << endl;
	cout << "*********************5������ְ����Ϣ******************************" << endl;
	cout << "*********************6������ְ����Ϣ******************************" << endl;
	cout << "*********************7�����ְ����Ϣ******************************" << endl;
	cout << "********************************************************************" << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//Ҫ���ְ��������
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//����ָ��              newһ��ָ��
		Worker** newSpace = new Worker * [newSize];//newSpaceΪһ��ָ������
		//��ԭ���ռ�����ݿ������¿ռ�
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//ѡ��Ĳ���
			cout << "�������" << i + 1 << "ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}
			newSpace[this->m_EmpNum+i] = worker;
		}
		//�ͷ�ԭ���Ŀռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_EmpNum = newSize;
		//���ı�־λ
		this->m_FileEmpty = false;
		//�����ļ�
		this->save();
		cout << "�ɹ����" << addNum << "��" << endl;

		//��������������ص����˵�
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
	}
}


void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


int WorkerManager::getNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	
	int  num = 0;

	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}
	ifs.close();
	return num;
}


void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int i = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		Worker* worker = NULL;
		if (dId==1)
		{
			worker = new employee(id, name, dId);
		}
		else if(dId==2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) 
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[i] = worker;
		i++;
	}
}


void WorkerManager::show_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬��������Ľӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


int WorkerManager::IsExist(int Id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == Id) {
			index = i;
			break;
		}
	}
	return index;
}


void WorkerManager::Del_Emp()
{
	if (this->m_FileEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int Id;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> Id;
		int index = this->IsExist(Id);
		if (index!=-1)
		{
			for (int i = Id; i < this->m_EmpNum; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			delete this->m_EmpArray[this->m_EmpNum - 1];
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	system("pause");
	system("cls");
}


void WorkerManager::Find()
{
	int id;
	string name;
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select==1)
		{
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1) {
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "���ҳɹ������˵���Ϣ��" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else if (select == 2) {
			cout << "������Ҫ���ҵ�ְ������:" << endl;
			cin >> name;
			bool res = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name) {
					res = true;
					cout << "���ҳɹ������˵���Ϣ��" << endl;
					this->m_EmpArray[i]->showInfo();
				}

			}
			if (res==false)
			{
				cout << "���޴���" << endl;
			}
		}
		else 
		{
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::sort_Emp()
{
	
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ����Ž�������" << endl;
		cout << "2����ְ����Ž��н���" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum-1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++) 
			{
				if (select == 1) {
					if (this->m_EmpArray[j]->m_Id>this->m_EmpArray[j+1]->m_Id)
					{
						Worker* temp = this->m_EmpArray[j+1];
						this->m_EmpArray[j + 1] = this-> m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
				else
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* temp = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
			}
		}
		this->save();
		cout << "����ɹ���������Ϊ��" << endl;
		this->show_Emp();
	}
	system("pause");
	system("cls");
}


void WorkerManager::modify()
{
	int Id;
	int newId;
	string newName;
	int newDselect;
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
else 
	{
		cout << "������Ҫ���ĵ�ְ�����" << endl;
		cin >> Id;
		int result = this->IsExist(Id);
		if (result == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			delete this->m_EmpArray[result];
			cout << "�鵽" << Id << "��ְ�����������µ�ְ�����" << endl;
			cin >> newId;
			cout << "�������������� " << endl;
			cin >> newName;
			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newDselect;
			Worker* worker = NULL;
			switch (newDselect)
			{
			case 1:
				worker = new employee(newId, newName, newDselect);
				break;
			case 2:
				worker = new Manager(newId, newName, newDselect);
				break;
			case 3:
				worker = new Boss(newId, newName, newDselect);
				break;
			default:
				break;
			}
			this->m_EmpArray[result] = worker;
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::clean_file()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
