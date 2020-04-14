#include "WorkerManager.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include<cstdlib>
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//如果文件为空
	if (!ifs.is_open()) {
		cout << "empty" << endl;//测试代码
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		cout << "职工人数为0" << endl;
		return;
	}
	//文件存在，并记录数据
	int num = this->getNum();
	cout << "当前职工个数：" << num << endl;//测试代码
	this->m_EmpNum = num;

	//将文件的数据存到数组
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
	cout << "*********************欢迎使用职工管理系统************************" << endl;
	cout << "*********************0、退出管理程序******************************" << endl;
	cout << "*********************1、增加职工信息******************************" << endl;
	cout << "*********************2、显示职工信息******************************" << endl;
	cout << "*********************3、删除职工信息******************************" << endl;
	cout << "*********************4、修改职工信息******************************" << endl;
	cout << "*********************5、查找职工信息******************************" << endl;
	cout << "*********************6、排序职工信息******************************" << endl;
	cout << "*********************7、清空职工信息******************************" << endl;
	cout << "********************************************************************" << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;//要添加职工的数量
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//数组指针              new一个指针
		Worker** newSpace = new Worker * [newSize];//newSpace为一个指针数组
		//将原来空间的数据拷贝到新空间
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//选择的部门
			cout << "请输入第" << i + 1 << "职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
		//释放原来的空间
		delete[] this->m_EmpArray;
		//更新新空间的指针
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//更改标志位
		this->m_FileEmpty = false;
		//保存文件
		this->save();
		cout << "成功添加" << addNum << "人" << endl;

		//按任意键清屏，回到主菜单
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误" << endl;
	}
}


void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用子类的接口
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int Id;
		cout << "请输入要删除的职工编号：" << endl;
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select==1)
		{
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1) {
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "查找成功，此人的信息：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else if (select == 2) {
			cout << "请输入要查找的职工姓名:" << endl;
			cin >> name;
			bool res = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name) {
					res = true;
					cout << "查找成功，此人的信息：" << endl;
					this->m_EmpArray[i]->showInfo();
				}

			}
			if (res==false)
			{
				cout << "查无此人" << endl;
			}
		}
		else 
		{
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::sort_Emp()
{
	
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工编号进行升序" << endl;
		cout << "2、按职工编号进行降序" << endl;
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
		cout << "排序成功，排序结果为：" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
else 
	{
		cout << "请输入要更改的职工编号" << endl;
		cin >> Id;
		int result = this->IsExist(Id);
		if (result == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			delete this->m_EmpArray[result];
			cout << "查到" << Id << "号职工，请输入新的职工编号" << endl;
			cin >> newId;
			cout << "请输入新姓名： " << endl;
			cin >> newName;
			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			cout << "修改成功" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::clean_file()
{
	cout << "确定清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		//打开模式 ios::trunc 如果存在删除文件并重新创建
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
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
